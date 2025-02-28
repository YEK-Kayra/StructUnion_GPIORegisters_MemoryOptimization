#include<stdio.h>
#include<stdint.h>

struct GPB1_BITS
{
    uint16_t  GPIO32:2;           // 1:0  GPIO32
    uint16_t  GPIO33:2;           // 3:2  GPIO33
    uint16_t  GPIO34:2;           // 5:4  GPIO34
    uint16_t  GPIO35:2;           // 7:6  GPIO35
    uint16_t  GPIO36:2;           // 9:8  GPIO36
    uint16_t  GPIO37:2;           // 11:10    GPIO37
    uint16_t  GPIO38:2;           // 13:12    GPIO38
    uint16_t  GPIO39:2;           // 15:14    GPIO39
    uint16_t  GPIO40:2;           // 17:16    GPIO40
    uint16_t  GPIO41:2;           // 19:18    GPIO41
    uint16_t  GPIO42:2;           // 21:20    GPIO42
    uint16_t  GPIO43:2;           // 23:22    GPIO43
    uint16_t  GPIO44:2;           // 25:24    GPIO44
    uint16_t  rsvd1:6;            // 31:26    Reserved
};


//Union içinde 4byte ı ya all ifadesi ile ya da bit ifadesinden gelenler ile dolduracağım
//Ama union benim işlemcimin hafızasında toplamda 4byte yer kaplayacak. Burayı union ile tanımlamayıp struct ile tanımlasaydım
//O zaman 4byte all değişkeninden, 4byte da bit değişkeninden gelecekti, 8byte toplam kaplanan alan olacaktı 
struct GPB1_REG
{
    uint32_t all;	         //Tanımlama türünden dolayı 32bit yani 4bytelık alan kaplayacak
    struct GPB1_BITS    bit;	 //Toplamında 32bit vardır yani 4bytelık alan kaplayacak
};


struct GPIO_CTRL_REGS
{
struct	GPB1_REG        GPBMUX1;
};






int main(){
	
	struct GPIO_CTRL_REGS GpioCtrlRegs;	//Ana degiskeni tanımladık

	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 2;
	
	printf("Degiskenimizin kapladiği yer : %d byte\n", sizeof(GpioCtrlRegs));			//Çalıştırıldığında 8 byte yazacaktır.
	printf("Degiskenimizin kapladiği yer : %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1));		//Çalıştırıldığında 8 byte yazacaktır.
	printf("Degiskenimizin kapladiği yer : %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.all));		//Çalıştırıldığında 4 byte yazacaktır.
	printf("Degiskenimizin kapladiği yer : %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.bit));		//Çalıştırıldığında 4 byte yazacaktır.
	//printf("Degiskenimizin kapladiği yer : %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.bit.GPIO33));//Program bitfield lara dokunamaz,	
	
	
}