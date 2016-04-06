/*
 * SPI_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/*************************************************************/
/*Comment:Choose prescaler
 * Range:SPI_u8Factor(2~128)
 * */
#define SPI_u8PreScaler			SPI_u8Factor16
/*************************************************************/
/*Comment:Choose Your Mode
 * Range: SPI_u8Slave(Debug) or SPI_u8Master(Release)
 * */
#define SPI_u8Mode		SPI_u8Master

/*************************************************************/
#endif /* SPI_CONFIG_H_ */
