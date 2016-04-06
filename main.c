#include "Types.h"
#include "DIO_Private.h"
#include "DIO_interface.h"
#include "SPI_Private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "delay.h"

int main (void)
{
	//DIO_VoidInit();
	#if (SPI_u8Mode==SPI_u8Master)
	SPI_VoidMasterInit();
	#elif (SPI_u8Mode==SPI_u8Slave)
	SPI_VoidSlaveInit();
	#endif
	while(1)
	{
		#if (SPI_u8Mode==SPI_u8Master)
		SPI_VoidMasterTransmit(0xf5);
		Delay_ms_Max1s(500);
		#elif (SPI_u8Mode==SPI_u8Slave)
		if(SPI_VoidSlaveReceive()==0xf5)
			PORTC=0xff;
		else;
		#endif
	}
	return 0;
}
