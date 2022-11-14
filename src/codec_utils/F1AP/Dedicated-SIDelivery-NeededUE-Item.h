/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "../F1.asn1"
 * 	`asn1c -D ../F1_output/ -fcompound-names -fno-include-deps -findirect-choice -gen-PER`
 */

#ifndef	_Dedicated_SIDelivery_NeededUE_Item_H_
#define	_Dedicated_SIDelivery_NeededUE_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GNB-CU-UE-F1AP-ID.h"
#include "NRCGI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Dedicated-SIDelivery-NeededUE-Item */
typedef struct Dedicated_SIDelivery_NeededUE_Item {
	GNB_CU_UE_F1AP_ID_t	 gNB_CU_UE_F1AP_ID;
	NRCGI_t	 nRCGI;
	struct ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Dedicated_SIDelivery_NeededUE_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Dedicated_SIDelivery_NeededUE_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _Dedicated_SIDelivery_NeededUE_Item_H_ */
#include <asn_internal.h>
