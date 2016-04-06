/*
 * SPI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VoidMasterInit(void);
void SPI_VoidMasterTransmit(u8 SPI_u8Data);
void SPI_VoidSlaveInit(void);
u8 SPI_VoidSlaveReceive(void);




#endif /* SPI_INTERFACE_H_ */
