#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef struct
{
    int x, y;
    int pontos=0;
    bool vida=true;
} Snake;

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

string mapa[21] =
{
    "‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "€                                       €",
    "ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ"
};

void MyMap(int x, int y)
{
            for(int i=0; i<5; i++)
    {
        do{

        x=rand()%(39)+1;
        y=rand()%(19)+1;

        }while(mapa[y][x]=='€');//VereficaÁ„o para n„o spawnar em cima da maÁ„
            mapa[y][x]='€';
    }

    for(int i=0; i<21; i++)
    {
        Sleep(100);
        cout<<mapa[i]<<endl;
    }
}

void DrawW(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, 2);
    cout<<"v";
}

void DrawA(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, 2);
    cout<<">";
}

void DrawS(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, 2);
    cout<<"^";
}

void DrawD(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, 2);
    cout<<"<";
}

void Delete(int x, int y)
{
    gotoxy(x,y);
    cout<<" ";
}

void Pontos(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    x=rand()%(39)+1;
    y=rand()%(19)+1;

    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, 4);
    mapa[y][x]='œ';
    cout<<mapa[y][x];
}

int main()
{
    srand(time(NULL));

    int x=20;
    int y=10;
    char tecla;
    char mov;
    Snake p1;
    p1.x=20;
    p1.y=10;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO ConCurInf;//Configura o cursor
    ConCurInf.dwSize = 10;//Define o tamanho do cursor
    ConCurInf.bVisible = FALSE;//Deixa o cursor invisivel
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);

    gotoxy(0,0);
    MyMap(x,y);

    DrawW(p1.x,p1.y);

    Pontos(x,y);

    while(true)
    {
        Sleep(300);

        if(kbhit())
        {
            mov=getch();

            if(mov=='W'||mov=='w'||mov=='A'||mov=='a'||mov=='S'||mov=='s'||mov=='D'||mov=='d')
            {
                tecla=mov;
            }
        }

        switch(tecla)
        {

        case 'W':
        case 'w':
            Delete(p1.x,p1.y);
            if((p1.y)<=1)
            {
                p1.y=1;
            }//Borda do Mapa 'W'
            if(mapa[y][x]==' ' || mapa[y][x]=='œ')
            {
                p1.y--;
            }//Colis„o 'W'
            if(mapa[p1.y][p1.x]=='‹' || mapa[p1.y][p1.x]=='€')
            {
                p1.vida=false;
            }//CondiÁ„o para Game Over 'W'
            DrawW(p1.x,p1.y);

            if(mapa[p1.y][p1.x]=='œ')
            {
                p1.pontos+=1;
                mapa[p1.y][p1.x]=' ';

                Pontos(x,y);
            }//PontuaÁ„o 'W'
            break;

        case 'A':
        case 'a':
            Delete(p1.x,p1.y);

            if((p1.x)<=1)
            {
                p1.x=1;
            }//Borda do Mapa 'A'
            if(mapa[y][x]==' ' || mapa[y][x]=='œ')
            {
                p1.x--;
            }//Colis„o 'A'
            if(mapa[p1.y][p1.x]=='‹' || mapa[p1.y][p1.x]=='€')
            {
                p1.vida=false;
            }//CondiÁ„o para Game Over 'A'
            DrawA(p1.x,p1.y);

            if (mapa[p1.y][p1.x]=='œ')
            {
                p1.pontos+=1;
                mapa[p1.y][p1.x]=' ';

                Pontos(x,y);
            }//PontuaÁ„o 'A'

            break;

        case 'S':
        case 's':
            Delete(p1.x,p1.y);
            if((p1.y)>=20)
            {
                p1.y=20;
            }//Borda do Mapa 'S'
            if(mapa[y][x]==' ' || mapa[y][x]=='œ')
            {
                p1.y++;
            }//Colis„o 'S'
            if(mapa[p1.y][p1.x]=='‹' || mapa[p1.y][p1.x]=='ﬂ' || mapa[p1.y][p1.x]=='€')
            {
                p1.vida=false;
            }//CondiÁ„o para Game Over 'S'
            DrawS(p1.x,p1.y);

            if (mapa[p1.y][p1.x]=='œ')
            {
                p1.pontos+=1;
                mapa[p1.y][p1.x]=' ';

                Pontos(x,y);
            }//PontuaÁ„o 'S'

            break;

        case 'D':
        case 'd':
            Delete(p1.x,p1.y);
            if((p1.x)>=40)
            {
                p1.x=40;
            }//Borda do Mapa 'D'
            if(mapa[y][x]==' ' || mapa[y][x]=='œ')
            {
                p1.x++;
            }//Colis„o 'D'
            if(mapa[p1.y][p1.x]=='‹' || mapa[p1.y][p1.x]=='€')
            {
                p1.vida=false;
            }//CondiÁ„o para Game Over 'D'
            DrawD(p1.x,p1.y);

            if (mapa[p1.y][p1.x]=='œ')
            {
                p1.pontos+=1;
                mapa[p1.y][p1.x]=' ';

                Pontos(x,y);
            }//PontuaÁ„o 'D'
            break;

        default:
            break;
        }
    if(p1.vida==false)
    {
        gotoxy(2,22);
        cout<<"Game Over!";

        gotoxy(2,24);
        cout<<"Score: "<<p1.pontos;

        gotoxy(2,26);
        cout<<"Pressione qualquer tecla para sair...";
        getch();
        gotoxy(2,27);
        cout<<"Pressione novamete para confirmar!";
        gotoxy(2,28);
        exit(0);
    }
    gotoxy(43,1);
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"Pontos: "<<p1.pontos;
    }
    return 0;
}

