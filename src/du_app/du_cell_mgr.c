/*******************************************************************************
################################################################################
#   Copyright (c) [2017-2019] [Radisys]                                        #
#                                                                              #
#   Licensed under the Apache License, Version 2.0 (the "License");            #
#   you may not use this file except in compliance with the License.           #
#   You may obtain a copy of the License at                                    #
#                                                                              #
#       http://www.apache.org/licenses/LICENSE-2.0                             #
#                                                                              #
#   Unless required by applicable law or agreed to in writing, software        #
#   distributed under the License is distributed on an "AS IS" BASIS,          #
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
#   See the License for the specific language governing permissions and        #
#   limitations under the License.                                             #
################################################################################
*******************************************************************************/

/* This file contains message handling functionality for DU APP */
#include "du_cell_mgr.h"

extern DuCfgParams duCfgParam;

extern S16 duBuildAndSendMacCellCfg();

/*******************************************************************
 *
 * @brief Processes cells to be activated
 *
 * @details
 *
 *    Function : procCellsToBeActivated
 *
 *    Functionality:
 *      - Processes cells to be activated list received in F1SetupRsp
 *
 * @params[in] void
 * @return ROK     - success
 *         RFAILED - failure
 *
 * ****************************************************************/
S16 procCellsToBeActivated(Cells_to_be_Activated_List_t cellsToActivate)
{
   U16 idx = 0;
   S16 ret = ROK;

   for(idx=0; idx<cellsToActivate.list.count; idx++)
   {
      U16 nci = 0;
      U16 pci = 0;
      DuCellCb *cellCb = NULLP;

      Cells_to_be_Activated_List_Item_t cell = cellsToActivate.list.array[idx]->\
          value.choice.Cells_to_be_Activated_List_Item;

      bitStringToInt(&cell.nRCGI.nRCellIdentity, &nci);
      if(nci <= 0 || nci > DU_MAX_CELLS)
      {
         DU_LOG("\nDU APP : Invalid NCI %d", nci);
         return RFAILED;
      }

      if(cell.nRPCI)
      {
         pci = *cell.nRPCI;
      }

      cellCb = duCb.cfgCellLst[nci-1];

      if(!cellCb)
      {
         DU_LOG("\nDU APP : No Cell found for NCI %d", nci);
         return RFAILED;
      }
      cellCb->cellStatus = ACTIVATION_IN_PROGRESS; 
      cellCb->cellInfo.nrPci = pci;

      /* Now remove this cell from configured list and move to active list */
      duCb.cfgCellLst[nci-1] = NULLP;
      duCb.actvCellLst[nci-1] = cellCb;

      /* Build and send Mac Cell Cfg for the number of active cells */
      ret = duBuildAndSendMacCellCfg();
      if(ret != ROK)
      {
         DU_LOG("\nDU APP : macCellCfg build and send failed");
         return RFAILED;
      }
   }
   return ret;
}

/******************************************************************
*
* @brief Processes F1 Setup Response sent by CU
*
* @details
*
*    Function : procF1SetupRsp
*
*    Functionality: Processes F1 Setup Response sent by CU
*
* @params[in] F1AP_PDU_t ASN decoded F1AP message
* @return ROK     - success
*         RFAILED - failure
*
* ****************************************************************/
S16 procF1SetupRsp(F1AP_PDU_t *f1apMsg)
{
   S16 ret = ROK;

   F1SetupResponse_t *f1SetRspMsg;
   F1SetupRsp    f1SetRspDb;
   GNB_CU_Name_t *cuName;
   RRC_Version_t *rrc_Ver;
   U16 idx;

   DU_LOG("\nDU_APP : F1 Setup Response received"); 
 	printf("\nDU_APP : F1 Setup Response received");
   duCb.f1Status = TRUE; //Set F1 status as true
   f1SetRspMsg = &f1apMsg->choice.successfulOutcome->value.choice.F1SetupResponse;

   for(idx=0; idx<f1SetRspMsg->protocolIEs.list.count; idx++)
   {
//      F1SetupResponseIEs_t f1RspIe = f1SetRspMsg->protocolIEs.list.array[idx];
      switch(f1SetRspMsg->protocolIEs.list.array[idx]->id)
      {
         case ProtocolIE_ID_id_Cells_to_be_Activated_List:
         {
            procCellsToBeActivated(f1SetRspMsg->protocolIEs.list.array[idx]->\
                  value.choice.Cells_to_be_Activated_List);
            break;
         }
         //TODO: where to store and how to use below variables?can they be skipped
         case ProtocolIE_ID_id_TransactionID:
         {
            f1SetRspDb.transId = f1SetRspMsg->protocolIEs.list.array[idx]->\
                                 value.choice.TransactionID;
            break;
         }
         case ProtocolIE_ID_id_gNB_CU_Name:
         {
            cuName = &f1SetRspMsg->protocolIEs.list.array[idx]->\
                     value.choice.GNB_CU_Name;
            strcpy(f1SetRspDb.cuName, (const char*)cuName->buf);
            break;
         }
         case ProtocolIE_ID_id_GNB_CU_RRC_Version:
         {
            rrc_Ver = &f1SetRspMsg->protocolIEs.list.array[idx]->\
                      value.choice.RRC_Version;
            strcpy(f1SetRspDb.rrcVersion.rrcVer,
                  (const char*)rrc_Ver->latest_RRC_Version.buf);
            break;
         }
         default:
            DU_LOG("\nDU_APP : Invalid IE received in F1SetupRsp:%ld",
                  f1SetRspMsg->protocolIEs.list.array[idx]->id);
      }
   }
 
   /* TODO :Check the deallocation */
#if 0
   SPutSBuf(DU_APP_MEM_REGION, DU_POOL,(Data *)&(f1SetupRsp->protocolIEs.list.array),\
         (Size)elementCnt * sizeof(F1SetupResponseIEs_t *));
   SPutSBuf(DU_APP_MEM_REGION, DU_POOL,(Data *)&(f1apMsg->choice.successfulOutcome),\
         (Size)sizeof(SuccessfulOutcome_t));
   SPutSBuf(DU_APP_MEM_REGION, DU_POOL,(Data *)&f1apMsg,(Size)sizeof(F1AP_PDU_t));
#endif
 
   return ret;
}

/**********************************************************************
  End of file
 **********************************************************************/
