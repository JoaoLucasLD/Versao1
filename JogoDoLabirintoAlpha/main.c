#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#define H 11
#define W 20


int x = 0, y = 5, pontos = 4;

char i, j;

void draw(int, int);
void control();

void menu()
{

    int opcao;

    printf("Bem-vindo(a) ao Jogo do Labirinto!\n------------------------------------");
    printf("\nDigite 1 para comecar o jogo.\n");
    printf("\nDigite 2 para mostrar as instrucoes e controles.\n");
    printf("\nDigite 3 para sair.\n\n");

    scanf("%d", &opcao);

    switch(opcao)
    {

    case 1:
        printf("Pressione alguma seta do teclado para iniciar o jogo.");
        control();
        break;

    case 2:
        printf("\nO objetivo do jogo e chegar no portal verde localizado no lado oposto do spawn. Use as setinhas do teclado para se mover no mapa.\n\n");
        system("pause");
        printf("\n");
        menu();

    case 3:
        system("taskkill /IM cb_console_runner.exe");
        break;

    default:
        printf("\nOpcao invalida.\n");
        break;

    }
}

char map[H][W] =
{
    {1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
    {1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,5,0,5,5,5,5,5,5,5,5,0,5,5,5,5,5,0,1},
    {1,0,5,0,5,0,0,4,5,0,0,0,0,5,0,0,0,5,4,1},
    {1,0,5,0,5,0,5,5,5,0,5,5,0,5,0,5,0,5,5,3},
    {0,0,0,0,5,0,5,0,0,0,5,0,0,5,0,5,0,0,0,0},
    {1,0,5,5,5,0,5,0,5,5,5,5,5,5,0,5,5,5,0,3},
    {1,0,0,0,5,0,5,0,5,0,0,0,0,0,0,5,0,0,0,1},
    {1,5,5,0,5,0,5,0,5,0,5,5,5,5,5,5,0,5,0,1},
    {1,4,0,0,0,0,5,0,0,0,0,5,4,0,0,0,0,5,0,1},
    {5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},

};

int main()
{

    menu();

    while(true)
    {

        control();

        Sleep(100);

        if(map[y-1][x] == 3)
        {
            pontuacao();
            printf("\nVoce chegou ao final do mapa, parabens! Sua pontuacao foi %d\n", pontos);
            Sleep(2000);
            printf("\nVoce chegou ao final do mapa, parabens! Sua pontuacao foi %d\n", pontos);
            Sleep(2000);
            printf("\nVoce chegou ao final do mapa, parabens! Sua pontuacao foi %d\n", pontos);
            Sleep(5000);
            break;

        }
    }
}

void draw(int py, int px)
{

    map[y][x] = 0;

    x += px;
    y += py;
    map[y][x] = 7;

    system("cls");

    for(i = 0; i < H; i++)
    {

        for(j = 0; j < W; j++)
        {

            switch(map[i][j])
            {
            case 0:
                printf(" %c ", 255);
                break;
            case 1:
                printf(" %c ", 254);
                break;
            case 2:
                printf("\033[0;34m");
                printf(" %c ", 254);
                printf("\033[0;37m");
                break;
            case 3:
                printf("\033[0;32m");
                printf(" %c ", 254);
                printf("\033[0;37m");
                break;
            case 4:
                printf("\033[0;33m");
                printf(" %c ", 004);
                printf("\033[0;37m");
                break;
            case 5:
                printf(" %c ", 254);
                break;
            case 6:
                printf(" %c ", 254);
                break;
            case 7:
                printf("\033[1;31m");
                printf(" %c ", 254);
                printf("\033[0;37m");
                break;
            }
        }
        printf("\n");
    }
    getch();
}

int pontuacao()
{

    for(i = 0; i < H; i++)
    {

        for(j = 0; j < W; j++)
        {
            if(map[i][j] == 4)
            {
                pontos--;
            }
        }
    }
}

void control()
{

         if(GetAsyncKeyState(VK_LEFT)  && (map[y][x-1] == 0 || map[y][x-1] == 2 || map[y][x-1] == 4) ) draw( 0,-1);
    else if(GetAsyncKeyState(VK_RIGHT) && (map[y][x+1] == 0 || map[y][x+1] == 2 || map[y][x+1] == 4) ) draw( 0, 1);
    else if(GetAsyncKeyState(VK_UP)    && (map[y-1][x] == 0 || map[y-1][x] == 2 || map[y-1][x] == 4) ) draw(-1, 0);
    else if(GetAsyncKeyState(VK_DOWN)  && (map[y+1][x] == 0 || map[y+1][x] == 2 || map[y+1][x] == 4) ) draw( 1, 0);
    else if(GetAsyncKeyState(VK_ESCAPE)) exit(0);

}


