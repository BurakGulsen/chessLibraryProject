#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

   
    void (*satrancFonskiyonlari)(char,struct poz)= &hareketYazdir;


    char a;
    int b;
   
    printf("Lutfen tasi konumlandirmak istediginiz yerin duseydeki yerini belirlemek icin A-H arasinda bir harf secin! \n");
    scanf("%c",&a);
    printf("Lutfen tasi konumlandirmak istediginiz yerin yataydaki yerini belirlemek icin 1-8 arasinda bir sayi secin! \n");
    scanf("%d",&b);

    struct poz f;
    f.dusey  = a;
    f.yatay = b;

    char tas;
    printf("Lutfen hareket alanini gormek istediginiz tasin bas harfini buyuk harf olacak sekilde yaziniz! ornek sah --> S gibi. \n");
   
    scanf(" %c",&tas);
    satrancFonskiyonlari(tas,f);
    getch();
    
    return 0;
}
