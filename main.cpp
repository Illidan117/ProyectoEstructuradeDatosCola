#include <C:\MinGW\include\allegro\include\allegro.h>
#include "inicia.h"
#include "inica2.h"
#include <iostream>
#include <stdio.h>
#include <sstream>

//lcd numbers from http://opengameart.org/content/lcd
using namespace std;
class nodo
{
public:
    int num;
    nodo* sig;
    nodo(int num)
    {
        this ->num =num;
        sig = NULL;
    }
};

class cola
{
public:
    nodo*inicio;
    cola()
    {
        inicio = NULL;
    }
    void push(int num)
    {
        nodo*nuevo = new nodo(num);

        if(empty())
        {
            inicio = nuevo;
        }
        else
        {

        //1
        nodo*temp=inicio;
        //2
        while (temp->sig!=NULL)
        {
            temp=temp->sig;
        }
        //3
        temp->sig = nuevo;
        }
    }
    void pop()
    {
        inicio = inicio->sig;
    }
    int front()
    {
        return inicio ->num;
    }


    bool empty()
    {
        return inicio == NULL;
    }

};
int main()
{
    int barra=45;
    cola stacker;
    inicia_allegro(300 ,425);
    inicia_audio(70,70);
    install_keyboard();
    set_color_depth(32) ;
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,300, 425, 0, 0)<0)     // swap with line below for windowed mode
        //if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 320, 200, 0, 0)<0)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Failure to init video mode!\n%s\n", allegro_error);
    }
    BITMAP  *ammo = NULL;
    BITMAP *deplete = NULL;
    BITMAP  *number1   = NULL;
    BITMAP  *number2   = NULL;
    BITMAP  *number3   = NULL;
    BITMAP  *number4   = NULL;
    BITMAP  *number5   = NULL;
    BITMAP  *number6   = NULL;
    BITMAP  *number7   = NULL;
    BITMAP  *number8   = NULL;
    BITMAP  *number9   = NULL;
    BITMAP  *number0   = NULL;
    BITMAP  *background   = NULL;
    BITMAP  *explosion= NULL;
    BITMAP  *success=NULL;
    BITMAP *buffer = create_bitmap(300, 425);
    success=load_bitmap("success.bmp",NULL);
    background=load_bitmap("Background.bmp",NULL);
    deplete =load_bitmap("deplete.bmp",NULL);
    ammo = load_bitmap("ammo.bmp",NULL);
    explosion =load_bitmap("boom.bmp",NULL);
    number1 = load_bitmap("lcd_1.bmp",NULL);
    number2 = load_bitmap("lcd_2.bmp",NULL);
    number3 = load_bitmap("lcd_3.bmp",NULL);
    number4 = load_bitmap("lcd_4.bmp",NULL);
    number5 = load_bitmap("lcd_5.bmp",NULL);
    number6 = load_bitmap("lcd_6.bmp",NULL);
    number7 = load_bitmap("lcd_7.bmp",NULL);
    number8 = load_bitmap("lcd_8.bmp",NULL);
    number9 = load_bitmap("lcd_9.bmp",NULL);
    number0 = load_bitmap("lcd_0.bmp",NULL);
    //int y = stacker.size();
    //stringstream gotcha;
    //gotcha << y;
    //string str = gotcha.str();
    //const char* x = str.c_str();
    draw_sprite(buffer, background, 0, 0);
    draw_sprite(screen, buffer, 0, 0);
    textout_ex(buffer, font, "Welcome Commander", 17, 25, 0xFFFF00, 0x000000);
    textout_ex(buffer, font, "Mision: Destroy Enemy Buildings", 17, 40, 0xFFFF00, 0x000000);
    textout_ex(buffer, font, "Target Lock Ready", 17, 55, 0xFFFF00, 0x000000);
    textout_ex(buffer, font, "Bombs are being loaded", 17, 70, 0xFFFF00, 0x000000);
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    for(int i = 10; i>0; i--)
    {
        draw_sprite(buffer, ammo, barra, 100);
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);
        barra = barra + 20;
        rest(500);
        stacker.push(i);
    }
    textout_ex(buffer, font, "Bombs are Ready, Press 1 to Fire", 17,70, 0xFFFF00, 0x000000);
    draw_sprite(buffer,number0,260,370);
    draw_sprite(buffer,number1,245,370);
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    while(!stacker.empty())
    {
        if(stacker.front()==10)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number0,245,370);
                draw_sprite(buffer,number9,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 50, 200);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);

                stacker.pop();
            }
        }
        if(stacker.front()==9)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number8,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 135,155);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==8)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number7,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 100,180);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==7)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number6,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 190,245);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==6)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number5,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion,175,225);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==5)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number4,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 95,170);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==4)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number3,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 75,235);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==3)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number2,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 80,200);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==2)
        {
            if(key[KEY_1])
            {
                barra = barra-20;
                draw_sprite(buffer,number1,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 160,190);
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                rest(1000);
                stacker.pop();
            }
        }
        if(stacker.front()==1)
        {
            if(key[KEY_1])
            {
                stacker.pop();
                barra = barra-20;
                draw_sprite(buffer,number0,260,370);
                draw_sprite(buffer, deplete, barra, 100);
                draw_sprite(buffer, explosion, 199,190);
            }
        }

    }
    draw_sprite(buffer, success, 50,200);
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    rest(1000);
    draw_sprite(buffer, success,50,200);
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    rest(5000);
    readkey();
}
END_OF_MAIN();
