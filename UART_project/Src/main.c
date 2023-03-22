#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include    "UART_int.h"


static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}


int	main(void)
{
	u8 data[100] ;

	/*	Initialization Part		*/

	/*	System Clk init			*/
	MRCC_voidSysClkInit();

	/*	Toggle Led A2 GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);

	/*	2- Enable Per Clk "RCC" USART1	*/
	MRCC_voidEnablePerClk(RCC_APB2,14);

	/* USART Initialization */ 
	MUSART_void_init() ;

	/*	Direction for A9 is output  */
	MDIO_voidSetPinDirection(PORTA, PIN9, OUT_2MHZ_AF_PP);

	/*	Direction for A10 is input  */
	MDIO_voidSetPinDirection(PORTA, PIN10, IN_FLOATING);


	while(1)
	{


#if 0
		MUSART_void_receiveString(data) ;

		MUSART_void_sendString(data) ;
#endif

#if 0
		MUSART_void_sendByte('a') ;
		MUSART_void_recieveByte(&data);
		if(data == '1')
		{
			MUSART_void_sendByte('x') ;
		}
		else
		{
			MUSART_void_sendByte('y') ;
		}
		_delay_ms(1000) ;
#endif
	}

	return 0;
}

