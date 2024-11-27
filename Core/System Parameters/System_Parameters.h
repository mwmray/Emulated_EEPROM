/*
 * System_Parameters.h
 *
 *  Created on: Nov 25, 2024
 *      Author: M.W Laptop
 */

#ifndef SYSTEM_PARAMETERS_SYSTEM_PARAMETERS_H_
#define SYSTEM_PARAMETERS_SYSTEM_PARAMETERS_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	float Jm;
	float Bm;
	struct memo_interface {
		uint8_t (*Flashmemo_Agnostic)(uint16_t Add, uint8_t *Val, uint16_t Len,
		bool R_W);
	} memo_interface_t;
	uint16_t Checksum;
} param_t;

extern param_t *paramdata;

typedef enum {
	success, failed, memo_error,
} stat_t;

uint16_t Compute_Checksum(uint8_t *Data, uint16_t Len);
stat_t Load_Param(uint16_t Add, uint8_t *Data);
stat_t Save_Param(uint8_t Add, uint8_t *Data, uint8_t Length);
stat_t Load_Default(uint8_t Add, uint8_t *Data, uint8_t Length);

#endif /* SYSTEM_PARAMETERS_SYSTEM_PARAMETERS_H_ */
