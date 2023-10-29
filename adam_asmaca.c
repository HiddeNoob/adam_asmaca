#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define KELIME_SAYISI 4
int rand_sayi(){
    srand(time(NULL));
    return rand() % 100;    
}
void yazdir_aski(){
    printf("\033[2;0H");
    printf(
        "    ________________  \n"
        "    |              |  \n"
        "    |              |  \n"
        "    |              |  \n"
        "    |                 \n"
        "    |                 \n"
        "    |                 \n"
        "    |                 \n"
        "    |                 \n"
        "    |                 \n"
        "    |                 \n"
        "  __|__               \n"
    );

}
void yazdir_adam(char yanlis_sayisi){
    printf("\033[6;0H");
    char satir[10][50] = {
        {"\t\t  ###     \n"},
        {"\t\t #   #    \n"},
        {"\t\t  ###     \n"},
        {"\t\t  /|\\    \n"},
        {"\t\t / | \\   \n"},
        {"\t\t/  |  \\  \n"},
        {"\t\t  / \\    \n"},
        {"\t\t /   \\   \n"}
    };
    for (int i = 0; i < yanlis_sayisi; i++)
    {
        printf("%s",satir[i]);
    }
    
}
void yazdir_kutu(char yanlis_sayisi){

    printf("\033[2J");
    printf("\033[0;0H");
    printf("-----------------------------\n");
    yazdir_aski();
    yazdir_adam(yanlis_sayisi);
    printf("\033[15;0H ----------------------------\n");
    for(int i = 0; i < 15; i++)printf("\033[%d;0H|",i+1);
    for(int i = 0; i < 15; i++)printf("\033[%d;30H|",i+1);
    printf("\n");


}


int main()
{
    bool game_finish = 0,win_rate = -1;
    char kelimeler[KELIME_SAYISI][25] = {"elma","kalem","elektrik","telefon"},girdi,yanlis_sayisi = 0;
    char *secilen_kelime = kelimeler[rand_sayi() % KELIME_SAYISI];
    short unsigned int kelime_length = strlen(secilen_kelime);
    char gozuken_kelime[kelime_length+2] = {};
    int hak_sayisi = kelime_length/2 - 1, yardim_sirasi = 0, dogru_kelime_sayisi = 0;
    for(int i = 0; i < kelime_length; i++ ) gozuken_kelime[i] = '_';

    do
    {
        yazdir_kutu(yanlis_sayisi);
        printf("Kelime %d Harfli! : %s\n",kelime_length,gozuken_kelime);
        printf("\nipucu istiyorsan '*' tusuna bas! (Kalan ipucu hakkin : %d)\nYada Kelime Tahmin Et!\n--> ",hak_sayisi);
        scanf("%c",&girdi);
        if(girdi == '*'){
            if(hak_sayisi > 0)
            {
                hak_sayisi--;
                gozuken_kelime[yardim_sirasi] = secilen_kelime[yardim_sirasi];
                yardim_sirasi++;
            }
            else{
                printf("\nHarf hakkiniz kalmadi");
                sleep(2);
                
            }
        }
        else if(girdi >= 'a' && girdi <= 'z'){
            bool bayrak = 0;
            for (int i = 0; i < kelime_length; i++)
            {
                if(girdi == secilen_kelime[i]){
                    bayrak = 1;
                    dogru_kelime_sayisi++;
                    if (dogru_kelime_sayisi == kelime_length)
                    {
                        game_finish = 1;
                        win_rate = 1;
                    }
                    
                    gozuken_kelime[i] = secilen_kelime[i];
                }
            }
            if (bayrak == 0){
                yanlis_sayisi++;
                if(yanlis_sayisi == 9){
                    game_finish = 1;
                    win_rate = 0;
                }
            }
        }
        fflush(stdin);

    }while(game_finish != 1);

    if (win_rate == 0)
    {
        printf("\033[2J");
        printf("\033[0;0H");
        printf(
            "                                      \n "
            "                                       \n"
            "                                      \n "
            "             KAYBETTINIZ               \n"
            "                                      \n "
            "                                      \n "
            "                                      \n "

            
            );
    }
    else{
        printf("\033[2J");
        printf("\033[0;0H");
        printf(
            "                                      \n "
            "                                       \n"
            "                                      \n "
            "             KAZANDINIZ               \n"
            "                                      \n "
            "                                      \n "
            "                                      \n "

            
            );
    }
    
}