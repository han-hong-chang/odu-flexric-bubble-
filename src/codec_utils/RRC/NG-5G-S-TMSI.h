/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NR-RRC-Definitions"
 * 	found in "../../../rrc_15.5.1_asn.asn1"
 * 	`asn1c -D ./rrc_out -fcompound-names -fno-include-deps -findirect-choice -gen-PER -no-gen-example`
 */

#ifndef	_NG_5G_S_TMSI_H_
#define	_NG_5G_S_TMSI_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NG-5G-S-TMSI */
typedef BIT_STRING_t	 NG_5G_S_TMSI_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NG_5G_S_TMSI_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NG_5G_S_TMSI;
asn_struct_free_f NG_5G_S_TMSI_free;
asn_struct_print_f NG_5G_S_TMSI_print;
asn_constr_check_f NG_5G_S_TMSI_constraint;
ber_type_decoder_f NG_5G_S_TMSI_decode_ber;
der_type_encoder_f NG_5G_S_TMSI_encode_der;
xer_type_decoder_f NG_5G_S_TMSI_decode_xer;
xer_type_encoder_f NG_5G_S_TMSI_encode_xer;
oer_type_decoder_f NG_5G_S_TMSI_decode_oer;
oer_type_encoder_f NG_5G_S_TMSI_encode_oer;
per_type_decoder_f NG_5G_S_TMSI_decode_uper;
per_type_encoder_f NG_5G_S_TMSI_encode_uper;
per_type_decoder_f NG_5G_S_TMSI_decode_aper;
per_type_encoder_f NG_5G_S_TMSI_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NG_5G_S_TMSI_H_ */
#include <asn_internal.h>