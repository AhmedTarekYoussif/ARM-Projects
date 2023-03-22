#if 1
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include    "PB_int.h"
#include	"SSD_int.h"
#include 	"LCD_int.h"


static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}


int	main(void)
{

	u8 value = NOT_PRESSED_ACTIVE_LOW;
	PB_t  PB1 = {1,PORTB,PIN11,ACTIVE_LOW};
	s32 i = 0 ;

	/*	Initialization Part		*/

	/*	System Clk init			*/
	MRCC_voidSysClkInit();

	/*	Toggle Led A2 GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);

	/*	2- Enable Per Clk "RCC" Port B		*/
	MRCC_voidEnablePerClk(RCC_APB2,3);


	/*	Direction for A2 is output Push Pull */
	MDIO_voidSetPinDirection(PORTA, PIN2, OUT_2MHZ_PP);

	/* init PB */
	H_PB_Void_init(&PB1);

	/* init SSD */
	H_SSD_Void_init();

	/* init LCD*/
	H_LCD_void_Init() ;
	while(1)
	{
		H_LCD_void_clear() ;
		H_LCD_void_sendString("My Name") ;
		_delay_ms(1000) ;
		H_LCD_void_clear() ;
		H_LCD_void_sendString("Ahmed Tarek") ;
		_delay_ms(1000) ;

#if 0
		/*	Toggle led using push button */
		/* read PB1 */
		H_PB_Void_read(&PB1, &value);
		if (value == PRESSED_ACTIVE_LOW) // check if PB is pressed
		{
			MDIO_voidTogPinValue(PORTA,PIN2) ; // led toggle
			i++ ;
			if(i>9)
			{
				i = 0 ;
			}
		}
		H_SSD_Void_DisplayNumber(i);

#endif
#if 0
		/* Test Seven Segment */

		for(i=20;i>= 0;i--)
		{
			H_SSD_Void_DisplayNumber(i);
		}
#endif
	}
	return 0;
}
#endif


