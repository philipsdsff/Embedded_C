//startup.c 
//Eng.philip


#include<stdint.h>
extern int main(void);

void  Reset_Handler();

void Default_Handler()
{
	Reset_Handler();
}
void  NMI_Handler()__attribute__((weak,alias("Default_Handler")));;
void  H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;

//booking 1024 Byte by .bss though uninitialize array  of int 256 Element (256*4=1024)


static unsigned long stack_top[256] ;

void(* const g_p_fn_vectors[])() __attribute__((section(".vectors")))=
{
(void(*)()) ((uint32_t)stack_top + sizeof(stack_top)),
(void(*)())	&Reset_Handler,
(void(*)())	&NMI_Handler,
(void(*)()) &H_Fault_Handler,

};



extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
void Reset_Handler(void)
{
	int i;
	// انا ششششبعمل بوينتر بيشاور على العنوان فى اللينكر و بحسب الفرق اللى ما بينهم و بعدين كده حسب المساحة اللى محتاجها السيكن ده 
	
	// copy .data from flash(ROM) into sram(RAM)
	unsigned char data_size = (unsigned char*)&_E_DATA  - (unsigned char*)&_S_DATA ;
	unsigned char* p_src = (unsigned char*)&_E_text ;
	unsigned char* p_dst = (unsigned char*)&_S_DATA ; //@##
	for(i = 0; i < data_size; i++)
	{
		// بالمساحة اللى حسبها من فرق  العنوانين فى اللينكر  increment بعمل
		*((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
		// @##rowبحط استريكز  علشان ادى قابلية للبوينتر انه يكتب عند و يكتب بالبنفس الداتا اللى موجوده فى ال
	}
	// init .bss with zero in sram
	unsigned char bss_size = (unsigned char*)&_E_bss  - (unsigned char*)&_S_bss ;	
	p_dst = (unsigned char*)&_S_bss ;
	for(i = 0; i < bss_size; i++)
	{
		*((unsigned char*)p_dst++) = (unsigned char)0 ;
	}
	// jump to main function
	main();
}