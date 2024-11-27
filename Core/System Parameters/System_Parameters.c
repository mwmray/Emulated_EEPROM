/*
 * System_Parameters.c
 *
 *  Created on: Nov 25, 2024
 *      Author: M.W Laptop
 */

#include"System_Parameters.h"

#define SizeOfParams (2 * (uint16_t)(((uint16_t *)&paramdata->Checksum) + 1 - (uint16_t *)paramdata))

const param_t Default_Param = { .Bm = 7.634 * 1e-4, .Jm = 0.0002 };

/// @fn uint16_t Compute_Checksum(uint8_t*, uint16_t)
/// @brief
/// compute the checksum to ensure data  integrity
/// @param Data
/// @param Len
/// @return
uint16_t Compute_Checksum(uint8_t *Data, uint16_t Len) {
	uint8_t *ptr = Data;
	uint16_t Checksum = 0;
	for (uint16_t x = 0; x < Len; x++) {
		Checksum += ptr[x];
	}
	return Checksum;
}

/// @fn stat_t Load_Param(uint16_t, uint8_t*)
/// @brief
/// Read parameters from memo
/// @param Add
/// @param Data
/// @return
stat_t Load_Param(uint16_t Add, uint8_t *Data) {
	if (Data != NULL) {
		paramdata->memo_interface_t.Flashmemo_Agnostic(Add, Data, SizeOfParams,
				1);
		uint16_t check = Compute_Checksum(Data,
		SizeOfParams - 2);
		return check == paramdata->Checksum ? success : failed;
	} else {
		return memo_error;
	}

}

/// @fn stat_t Save_Param(uint8_t, uint8_t*, uint8_t)
/// @brief
/// Write parameters into memo
/// @param Add
/// @param Data
/// @param Length
/// @return
stat_t Save_Param(uint8_t Add, uint8_t *Data, uint8_t Length) {
	if (Data == NULL || Length == 0) {
		return failed; // Return an error code for invalid parameters
	}
	paramdata->Checksum = Compute_Checksum(Data,
	SizeOfParams - 2);
	uint8_t status = paramdata->memo_interface_t.Flashmemo_Agnostic(Add, Data,
	SizeOfParams, 0);
	if (status != success) {
		return failed; // Return an error code for flash write failure
	}
	return success; // Return success code
}

/// @fn stat_t Load_Default(uint8_t, uint8_t*, uint8_t)
/// @brief
/// Load the default parameters values
/// @param Add
/// @param Data
/// @param Length
/// @return
stat_t Load_Default(uint8_t Add, uint8_t *Data, uint8_t Length) {
	//copy the default params to the memory
	if (Data != NULL) {
		memcpy(Data, &Default_Param, SizeOfParams);
		paramdata->Checksum = Compute_Checksum(Data,
		SizeOfParams - 2);
		Save_Param(Add, Data, Length);
		return success;
	} else {
		return failed;
	}
}
