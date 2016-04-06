/*
 * SPI_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/*Comment!:SPCR,SPSR And SPDR address  */
#define SPCR_u8Address	(0x2D)
#define SPSR_u8Address	(0x2E)
#define SPDR_u8Address	(0x2F)

#define SPDR_Register		(*(volatile u8 *) SPDR_u8Address)

#define SPCR_Register		(*(volatile u8 *) SPCR_u8Address)

typedef union
	{
			struct
			{
				u8 SPR0 :1 ;
				u8 SPR1 :1 ;
				u8 CPHA :1 ;
				u8 CPOL :1 ;
				u8 MSTR :1 ;
				u8 DORD	:1 ;
				u8 SPE	:1 ;
				u8 SPIE	:1 ;
			};
	}SPCR_Reg;

#define SPCR 		(*(volatile SPCR_Reg *) SPCR_u8Address)
#define SPCR_SPR0	SPCR.SPR0
#define SPCR_SPR1	SPCR.SPR1
#define SPCR_CPHA	SPCR.CPHA
#define SPCR_CPOL	SPCR.CPOL
#define SPCR_MSTR	SPCR.MSTR
#define SPCR_DORD	SPCR.DORD
#define SPCR_SPE	SPCR.SPE
#define SPCR_SPIE	SPCR.SPIE

#define SPI_u8SPE_6		6
#define SPI_u8MSTR_4	4

#define SPI_u8SPR1	5
#define SPI_u8CPHA	6
#define SPI_u8CPOL	7

#define SPI_u8SS	12
#define SPI_u8MOSI	13
#define SPI_u8MISO	14
#define SPI_u8SCK	15


#define SPSR_Register		(*(volatile u8 *) SPSR_u8Address)

	typedef union
		{
				struct
				{
					u8 SPI2X :1 ;
					u8 		 :5 ;
					u8 WCOL  :1 ;
					u8 SPIF	 :1 ;
				};
		}SPSR_Reg;


#define SPSR				(*(volatile SPSR_Reg *) SPSR_u8Address)
#define SPSR_SPI2X			SPSR.SPI2X
#define SPSR_WCOL			SPSR.WCOL
#define SPSR_SPIF			SPSR.SPIF

#define SPI_u8SPIF_7		7

#define 	SPR0_0		0
#define 	SPR1_1		1
#define 	SPI2X_0		0

#define 	SPI_u8Factor4		SPCR_Register|=(0<<SPR0_0 | 0<<SPR1_1 );SPSR_Register|=(0<<SPI2X_0 )
#define 	SPI_u8Factor16		SPCR_Register|=(1<<SPR0_0 | 0<<SPR1_1 );SPSR_Register|=(0<<SPI2X_0 )
#define 	SPI_u8Factor64		SPCR_Register|=(0<<SPR0_0 | 1<<SPR1_1 );SPSR_Register|=(0<<SPI2X_0 )
#define 	SPI_u8Factor128		SPCR_Register|=(1<<SPR0_0 | 1<<SPR1_1 );SPSR_Register|=(0<<SPI2X_0 )
#define 	SPI_u8Factor2		SPCR_Register|=(0<<SPR0_0 | 0<<SPR1_1 );SPSR_Register|=(1<<SPI2X_0 )
#define 	SPI_u8Factor8		SPCR_Register|=(1<<SPR0_0 | 0<<SPR1_1 );SPSR_Register|=(1<<SPI2X_0 )
#define 	SPI_u8Factor32		SPCR_Register|=(0<<SPR0_0 | 1<<SPR1_1 );SPSR_Register|=(1<<SPI2X_0 )
/*
#define 	SPI2X_u8Factor4			(0<<SPI2X_0 )
#define 	SPI2X_u8Factor16		(0<<SPI2X_0 )
#define 	SPI2X_u8Factor64		(0<<SPI2X_0 )
#define 	SPI2X_u8Factor128		(0<<SPI2X_0 )
#define 	SPI2X_u8Factor2			(1<<SPI2X_0 )
#define 	SPI2X_u8Factor8			(1<<SPI2X_0 )
#define 	SPI2X_u8Factor32		(1<<SPI2X_0 )
*/

#define		SPI_u8Slave			1
#define		SPI_u8Master		0


#endif /* SPI_PRIVATE_H_ */
