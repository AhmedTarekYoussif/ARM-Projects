#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include    "SPI_int.h"


static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}


#if 0
int	main(void)
{	
	/*	Initialization Part		*/

	/*	System Clk init			*/
	MRCC_voidSysClkInit();

	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);

	/*	2- Enable Per Clk "RCC" SPI1	*/
	MRCC_voidEnablePerClk(RCC_APB2,12);

	MDIO_voidSetPinDirection(PORTA,PIN0,OUT_50MHZ_PP) ;		/*SC(PA0)--> Output*/
	MDIO_voidSetPinDirection(PORTA,PIN5,OUT_50MHZ_AF_PP) ;	/*SCK(PA5) --> Output*/
	MDIO_voidSetPinDirection(PORTA,PIN6,IN_FLOATING) ;      /*MISO(PA6) --> Input*/
	MDIO_voidSetPinDirection(PORTA,PIN7,OUT_50MHZ_AF_PP) ;   /*MOSI(PA7) --> Output*/
	

	/* SPI Initialization */ 
	MSPI_void_initMaster() ;
	MDIO_voidSetPinValue(PORTA,PIN0,DIO_HIGH) ;    /*NSS(PA0)(Active high) = 1 */

	/*	Direction for A2 is output Push Pull */
	//MDIO_voidSetPinDirection(PORTA, PIN2, OUT_2MHZ_PP);

	while(1)
	{
		MSPI_void_sendByte(0xAA);
		_delay_ms(1000) ;

		/*
		 MSPI_void_sendByte('b');
		 _delay_ms(1000) ;
		 */
	}

	return 0;
}

#endif


#if 1
int	main(void)
{
	u8 data ;
	/*	Initialization Part		*/

	/*	System Clk init			*/
	MRCC_voidSysClkInit();

	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);

	/*	2- Enable Per Clk "RCC" SPI1	*/
	MRCC_voidEnablePerClk(RCC_APB2,12);

	MDIO_voidSetPinDirection(PORTA,PIN0,IN_FLOATING) ;		/*SC(PA0)--> INPUT*/
	MDIO_voidSetPinDirection(PORTA,PIN5,IN_FLOATING) ;		/*SCK(PA5) --> Output*/
	MDIO_voidSetPinDirection(PORTA,PIN6,OUT_50MHZ_AF_PP) ;   /*MISO(PA6) --> Input*/
	MDIO_voidSetPinDirection(PORTA,PIN7,IN_FLOATING) ;      /*MOSI(PA7) --> Output*/


	/* SPI Initialization */
	MSPI_void_initSlave() ;

	/*	Direction for A2 is output Push Pull */
	MDIO_voidSetPinDirection(PORTA, PIN2, OUT_2MHZ_PP);

	while(1)
	{
		MSPI_void_recieveByte(&data);

		if(data==0xAA)
		{
			MDIO_voidTogPinValue(PORTA, PIN2);
			_delay_ms(1000) ;
		}
		else
		{

		}

		/*
		 MSPI_void_sendByte('b');
		 _delay_ms(1000) ;
		 */
	}

	return 0;
}

#endif
