/*
 * SPI_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_Private.h"
#include "DIO-utilites.h"
#include "DIO_interface.h"
#include "SPI_Private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

/*****************************************************************/
#if SPI_u8Mode==SPI_u8Master
void SPI_VoidMasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	///DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	DIO_u8WritePinDir( SPI_u8MOSI,DIO_u8OUTPUT);
	DIO_u8WritePinDir( SPI_u8SCK,DIO_u8OUTPUT);
	DIO_u8WritePinDir( SPI_u8SS,DIO_u8OUTPUT);
	//in DIO_Config
	/* Enable SPI, Master, set clock rate fck/16 */
	//SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPCR_Register=(1<<SPI_u8SPE_6)|(1<<SPI_u8MSTR_4);//|SPI_u8PreScaler;
	SPI_u8PreScaler;
	//SPSR_Register=SPI_u8PreScaler_1;
}
/*****************************************************************/
void SPI_VoidMasterTransmit(u8 SPI_u8Data)
{
	/* Start transmission */
	DIO_u8WritePinVal(SPI_u8SS,DIO_u8LOW);
	SPDR_Register = SPI_u8Data;
	/* Wait for transmission complete */
	while(!(SPSR_Register & (1<<SPI_u8SPIF_7)));
	DIO_u8WritePinVal(SPI_u8SS,DIO_u8HIGH);
}
/*****************************************************************/
#elif SPI_u8Mode==SPI_u8Slave
void SPI_VoidSlaveInit(void)
{
	/* Set MISO output, all others input */
	//DDR_SPI = (1<<DD_MISO);
	DIO_u8WritePinDir( SPI_u8MISO,DIO_u8INPUT);
	DIO_u8WritePinDir( SPI_u8SS,DIO_u8INPUT);

	/* Enable SPI */
	SPCR_Register = (1<<SPI_u8SPE_6);
}
/*****************************************************************/

u8 SPI_VoidSlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR_Register & (1<<SPI_u8SPIF_7)));
	/* Return data register */
	return SPDR_Register;
}
#endif
