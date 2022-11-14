/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "../F1.asn1"
 * 	`asn1c -D ../F1_output/ -fcompound-names -fno-include-deps -findirect-choice -gen-PER`
 */

#ifndef	_PER_Scalar_H_
#define	_PER_Scalar_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PER-Scalar */
typedef long	 PER_Scalar_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PER_Scalar_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PER_Scalar;
asn_struct_free_f PER_Scalar_free;
asn_struct_print_f PER_Scalar_print;
asn_constr_check_f PER_Scalar_constraint;
ber_type_decoder_f PER_Scalar_decode_ber;
der_type_encoder_f PER_Scalar_encode_der;
xer_type_decoder_f PER_Scalar_decode_xer;
xer_type_encoder_f PER_Scalar_encode_xer;
oer_type_decoder_f PER_Scalar_decode_oer;
oer_type_encoder_f PER_Scalar_encode_oer;
per_type_decoder_f PER_Scalar_decode_uper;
per_type_encoder_f PER_Scalar_encode_uper;
per_type_decoder_f PER_Scalar_decode_aper;
per_type_encoder_f PER_Scalar_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PER_Scalar_H_ */
#include <asn_internal.h>
