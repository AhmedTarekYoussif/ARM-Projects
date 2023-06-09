/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 */
/*******************    Includes    ********************/
#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"ADC_int.h"
#include 	"LCD_int.h"


u16 global_u16Reading = 0;

int main(void)
{
	/******************* Initialization ********************/

	// System Clk init
	MRCC_voidSysClkInit();

	// Enable Per Clk "RCC" -> DIO_A , DIO_C, DIO_B
	MRCC_voidEnablePerClk(RCC_APB2,DIO_A);
	MRCC_voidEnablePerClk(RCC_APB2,DIO_C);
	MRCC_voidEnablePerClk(RCC_APB2,DIO_B);


	// Set ADC Prescaler
	MRCC_voidSetADCPre(RCC_ADC_PRE_2);

	// Enable Per Clk "RCC" -> ADC -> 9
	MRCC_voidEnablePerClk(RCC_APB2,9);

	// Set Direction for ADC channel_0 as IN_ANALOG
	M_DIO_void_setPinDir(PORTA, PIN0, IN_ANALOG);

	// Initialize ADC
	ADC_void_init();

	// Initialize LCD
	H_LCD_void_Init();

	// SET LEDs direction
	M_DIO_void_setPinDir(PORTA, PIN1, OUT_10MHZ_PP);
	M_DIO_void_setPinDir(PORTA, PIN2, OUT_10MHZ_PP);
	M_DIO_void_setPinDir(PORTC, PIN13, OUT_10MHZ_PP);
	M_DIO_void_setPinDir(PORTC, PIN14, OUT_10MHZ_PP);
	M_DIO_void_setPinDir(PORTC, PIN15, OUT_10MHZ_PP);


	/*******************   Super LOOP   ********************/
	while(1)
	{
		H_LCD_void_gotXY(0,1);
		H_LCD_void_sendString("ADC Value =");

		H_LCD_void_gotXY(1,6);
		global_u16Reading = ADC_u16_read(CHANNEL_0);
		if( (global_u16Reading>=0) && (global_u16Reading<10) )
		{
			H_LCD_void_sendIntNum(global_u16Reading & 0x000F);
		}
		else
		{
			H_LCD_void_sendIntNum(global_u16Reading);
		}

		if(global_u16Reading < 50)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_LOW);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_LOW);


		}
		else if(global_u16Reading < 100)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_HIGH);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_LOW);


		}
		else if(global_u16Reading < 400)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_LOW);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_HIGH);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_LOW);


		}
		else if(global_u16Reading < 600)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_LOW);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_HIGH);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_LOW);


		}
		else if(global_u16Reading < 800)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_LOW);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_HIGH);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_LOW);


		}
		else if(global_u16Reading < 1024)
		{
			M_DIO_void_setPinVal(PORTA, PIN1,  DIO_LOW);
			M_DIO_void_setPinVal(PORTA, PIN2,  DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN13, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN14, DIO_LOW);
			M_DIO_void_setPinVal(PORTC, PIN15, DIO_HIGH);


		}
		_delay_ms(250);
	}
	return 0;
}
