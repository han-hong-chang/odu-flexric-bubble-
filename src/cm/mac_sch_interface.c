/* header include files (.h) */
#include "envopt.h"        /* environment options */
#include "envdep.h"        /* environment dependent */
#include "envind.h"        /* environment independent */
#include "gen.h"           /* general */
#include "ssi.h"           /* system services */
#include "cm_tkns.h"       /* Common Token Defines */
#include "cm_llist.h"      /* Common Link List Defines */
#include "cm_hash.h"       /* Common Hash List Defines */
#include "cm_lte.h"        /* Common LTE Defines */
#include "cm_mblk.h"        /* Common LTE Defines */
#include "tfu.h"           /* RGU Interface defines */
#include "lrg.h"
//#include "fapi.h"

/* header/extern include files (.x) */
#include "gen.x"           /* general */
#include "ssi.x"           /* system services */
#include "cm_tkns.x"       /* Common Token Definitions */
#include "cm_llist.x"      /* Common Link List Definitions */
#include "cm_lib.x"        /* Common Library Definitions */
#include "cm_hash.x"       /* Common Hash List Definitions */
#include "cm_lte.x"        /* Common LTE Defines */
#include "cm_mblk.x"        /* Common LTE Defines */
#include "tfu.x"           /* RGU Interface includes */
#include "lrg.x"

#include "du_app_mac_inf.h"
#include "mac_sch_interface.h"

/**
 * @brief function to send Slot ind message from MAC
 *        to scheduler with loose coupling 
 *
 * @details
 *
 *     Function : packMacSchSlotInd
 *     
 *     
 *  @param[in]  Pst *pst, the post structure     
 *  @param[in]  *slotInd, the value of SFN and slot
 *  @return  S16
 *      -# ROK
 **/
int packMacSchSlotInd(Pst *pst, SlotIndInfo *slotInd)
{
   Buffer *mBuf = NULLP;
   if (SGetMsg(pst->region, pst->pool, &mBuf) != ROK)
   {
      RETVALUE(RFAILED);
   }

   /* pack SFN and slot value */
   CMCHKPK(SPkU16,slotInd->sfn, mBuf);
   CMCHKPK(SPkU16,slotInd->slot, mBuf);

   RETVALUE(SPstTsk(pst,mBuf));
}

/**
 * @brief function to pack DL Broadcast allocation message 
 *        from MAC to SCH
 *
 * @details
 *
 *     Function : packSchMaccDlBrdcstAlloc 
 *     
 *     
 *  @param[in]  Pst *pst, the post structure     
 *  @param[in]  *dlBrdcstAlloc, dlBroadcastAlloc
 *  @return  S16
 *      -# ROK
 **/
int packSchMacDlBrdcstAlloc(Pst *pst, DlBrdcstAlloc  *dlBrdcstAlloc)
{
	return ROK;
}

/**
 * @brief function to pack cell cfg from MAC to SCH
 *
 * @details
 *
 *     Function : packSchCellCfg 
 *     
 *     
 *  @param[in]  Pst *pst, the post structure     
 *  @param[in]  *schCellCfg, SchCellCfg structure
 *  @return  S16
 *      -# ROK
 **/
int packSchCellCfg(Pst *pst, SchCellCfg  *schCellCfg)
{
	return ROK;
}

/**
 * @brief function to pack cell cfg cfm from SCH to MAC
 *
 * @details
 *
 *     Function : packSchCellCfgCfm
 *     
 *     
 *  @param[in]  Pst *pst, the post structure     
 *  @param[in]  *schCellCfgCfm, SchCellCfgCfm structure
 *  @return  S16
 *      -# ROK
 **/
int packSchCellCfgCfm(Pst *pst, SchCellCfgCfm *schCellCfgCfm)
{
	return ROK;
}


/**********************************************************************
  End of file
 **********************************************************************/

