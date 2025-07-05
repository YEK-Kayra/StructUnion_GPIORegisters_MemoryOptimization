#include<stdio.h>
#include<stdint.h>

/**
 * @file     gpb1_bits_test.c
 * @brief    GPIO yapılarını test eden bir program
 * 
 * @details  Bu program, iki farklı yapı (struct) tanımlayarak bellek boyutlarını karşılaştırmaktadır.
 *           - `GPB1_BITS_version1`: Bit alanları (bit-fields) kullanılarak optimize edilmiş bir yapıdır.
 *           - `GPB1_BITS_version2`: Her GPIO değeri tam 16-bit olarak saklanan bir yapıdır.
 *           - Program, `sizeof()` fonksiyonunu kullanarak bellek farklarını gösterir.
 *
 * @author   [pwmcasso]
 * @date     [28.02.2025]
 * @version  1.0
 */
 
 
/**
 * @struct   GPB1_BITS_version1
 * @brief    Bit alanları kullanılarak oluşturulmuş GPIO kontrol yapısı
 * 
 * @details  Bit alanları (bit-fields) ile 32 bitlik bir yapıya sıkıştırılmıştır.
 *           13 GPIO pini için her biri 2 bitlik alan ayrılmıştır, 
 *           kalan 6 bit ise rezerve edilmiştir.
 *
 *		     reserveBitSayisi = 6 , GpioPiniSayisi = 13
 *			
 *			 Yani ((GpioPiniSayisi * 2bit) + reserveBitSayisi) ==> 32bit edecektir
 */ 
struct GPB1_BITS_version1
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

/**
 * @struct   GPB1_BITS_version2
 * @brief    Her GPIO değerini tam 16 bit olarak saklayan yapı
 * 
 * @details  Bit alanları kullanılmamıştır. Her GPIO için tam 16-bit ayrılmıştır,
 *           bu da toplamda daha fazla bellek tüketimine neden olur.
 *
 *			
 * 			GPIO_değişkenSayisi = 13 , reservedDegiskenSayisi = 1 
 *
 *		    Yani (GPIO_değişkenSayisi * 2byte) + (reservedDegiskenSayisi * 2byte) ==> 13*2 +1*2 = 28byte olarak gelir
 *			
 *			 
 */ 
struct GPB1_BITS_version2
{
    uint16_t  GPIO32;           // 1:0  GPIO32
    uint16_t  GPIO33;           // 3:2  GPIO33
    uint16_t  GPIO34;           // 5:4  GPIO34
    uint16_t  GPIO35;           // 7:6  GPIO35
    uint16_t  GPIO36;           // 9:8  GPIO36
    uint16_t  GPIO37;           // 11:10    GPIO37
    uint16_t  GPIO38;           // 13:12    GPIO38
    uint16_t  GPIO39;           // 15:14    GPIO39
    uint16_t  GPIO40;           // 17:16    GPIO40
    uint16_t  GPIO41;           // 19:18    GPIO41
    uint16_t  GPIO42;           // 21:20    GPIO42
    uint16_t  GPIO43;           // 23:22    GPIO43
    uint16_t  GPIO44;           // 25:24    GPIO44
    uint16_t  rsvd1;            // 31:26    Reserved
};


/**
 * @brief    Main fonksiyonu, iki struct türünün bellek kullanımını karşılaştırır.
 * @return   Program başarılı olursa 0 döner.
 */
int main(){
	
struct GPB1_BITS_version1 deneme_version1;
struct GPB1_BITS_version2 deneme_version2;

printf("deneme_version1 boyut  : %d  byte \n", sizeof(deneme_version1));	//Çalıştırıldığı takdirde "4 byte" yazacaktır
printf("deneme_version2 boyut  : %d byte \n", sizeof(deneme_version2));		//Çalıştırıldığı takdirde "28 byte" yazacaktır 	
	
}
