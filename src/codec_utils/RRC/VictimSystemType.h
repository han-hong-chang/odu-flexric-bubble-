/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NR-InterNodeDefinitions"
 * 	found in "../../../rrc_15.5.1_asn.asn1"
 * 	`asn1c -D ./rrc_out -fcompound-names -fno-include-deps -findirect-choice -gen-PER -no-gen-example`
 */

#ifndef	_VictimSystemType_H_
#define	_VictimSystemType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VictimSystemType__gps {
	VictimSystemType__gps_true	= 0
} e_VictimSystemType__gps;
typedef enum VictimSystemType__glonass {
	VictimSystemType__glonass_true	= 0
} e_VictimSystemType__glonass;
typedef enum VictimSystemType__bds {
	VictimSystemType__bds_true	= 0
} e_VictimSystemType__bds;
typedef enum VictimSystemType__galileo {
	VictimSystemType__galileo_true	= 0
} e_VictimSystemType__galileo;
typedef enum VictimSystemType__wlan {
	VictimSystemType__wlan_true	= 0
} e_VictimSystemType__wlan;
typedef enum VictimSystemType__bluetooth {
	VictimSystemType__bluetooth_true	= 0
} e_VictimSystemType__bluetooth;

/* VictimSystemType */
typedef struct VictimSystemType {
	long	*gps;	/* OPTIONAL */
	long	*glonass;	/* OPTIONAL */
	long	*bds;	/* OPTIONAL */
	long	*galileo;	/* OPTIONAL */
	long	*wlan;	/* OPTIONAL */
	long	*bluetooth;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VictimSystemType_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_gps_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_glonass_4;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_bds_6;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_galileo_8;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_wlan_10;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_bluetooth_12;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_VictimSystemType;
extern asn_SEQUENCE_specifics_t asn_SPC_VictimSystemType_specs_1;
extern asn_TYPE_member_t asn_MBR_VictimSystemType_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _VictimSystemType_H_ */
#include <asn_internal.h>