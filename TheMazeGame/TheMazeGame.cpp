#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sys/time.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x,y
    });
}

typedef struct
{
    int x, y;
    int points = 1000;
} Personagem;

unsigned char mapa[19][29] = {{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
                              {219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219},
                              {219,219,219,219,219,219,219,' ',' ',219,' ',' ',219,219,219,219,' ',' ',219,219,219,219,219,219,219,' ',' ',219},
                              {' ',' ',' ',' ',' ',' ',219,' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219},
                              {219,219,219,219,' ',' ',219,219,219,219,219,219,219,' ',' ',219,219,219,219,' ',' ',219,' ',' ',219,219,219,219},
                              {219,' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219},
                              {219,219,219,219,219,219,219,' ',' ',219,' ',' ',219,219,219,219,' ',' ',219,219,219,219,' ',' ',219,' ',' ',219},
                              {219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219},
                              {219,' ',' ',219,219,219,219,219,219,219,219,219,219,' ',' ',219,219,219,219,219,219,219,219,219,219,' ',' ',219},
                              {219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219},
                              {219,' ',' ',219,' ',' ',219,' ',' ',219,' ',' ',219,' ',' ',219,219,219,219,' ',' ',219,' ',' ',219,' ',' ',219},
                              {219,' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',219},
                              {219,' ',' ',219,219,219,219,219,219,219,' ',' ',219,219,219,219,' ',' ',219,219,219,219,219,219,219,' ',' ',219},
                              {219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,' ',' ',219},
                              {219,' ',' ',219,' ',' ',219,219,219,219,219,219,219,219,219,219,219,219,219,' ',' ',219,' ',' ',219,219,219,219},
                              {219,' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',219,' ',' ',219,' ',' ',' '},
                              {219,' ',' ',219,219,219,219,219,219,' ',' ',219,219,' ',' ',219,219,219,219,219,219,219,' ',' ',219,' ',' ',219},
                              {219,' ',' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219},
                              {219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219}
                              };

void PrintMapa()
{
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 29; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void Player(int x, int y)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Amarelo

    gotoxy(x, y);
    cout << "x";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco
}

void Delete(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void SaveScore(string name, int score)
{
    ofstream tabelaScores;
    tabelaScores.open("scores.txt", ios::app); // app: Abre para escrita sem deletar o conteudo atual

    // Verefica a quantidade de caracteres e altera o espaçamento entre "Name" e "Score"
    if(name.size() == 4)
    {
        tabelaScores << name << "             " << score << endl;
    }
    else if(name.size() == 3)
    {
        tabelaScores << name << "              " << score << endl;
    }
    else if(name.size() == 2)
    {
        tabelaScores << name << "               " << score << endl;
    }
    else if(name.size() == 1)
    {
        tabelaScores << name << "                " << score << endl;
    }

    tabelaScores.close();
}

void PrintScoreboard()
{
    string linha;
    ifstream scoreboard;

    scoreboard.open("scores.txt");

    if(scoreboard.is_open())
    {
        while(getline(scoreboard, linha))
        {
            cout << linha << endl;
        }
        scoreboard.close();
    }
    else
    {
        cout << "Nao foi possivel imprimir a tabela de scores";
    }
}

void Menu()
{
    int menu;
    bool inMenu = true;

    do // Menu
    {
        system("cls");

        cout << "--- The Maze Game ---" << endl << endl;

        cout << "(1) Jogar" << endl;
        cout << "(2) Scoreboard" << endl;
        cout << "(3) Sair" << endl;

        cin >> menu;

        switch(menu)
        {
        case 1:
            inMenu = false;

            break;

        case 2:
            system("cls");

            cout << "---- Scoreboard ----" << endl;
            cout << "Name            Score" << endl;
            PrintScoreboard();

            cout << endl << "Presione qualquer tecla para voltar...";
            getch();

            break;

        case 3:
            exit(0);

            break;

        default:
            cout << "Opcao invalida!" << endl;
            cout << "Tente novamente em 1s" << endl;

            Sleep(1000);
            system("cls");

            break;
        }
    }
    while(inMenu == true);
}

string InsertName()
{
    string name;
    char op;
    bool startGame;

    do // Escolha de nome para entrar no placar
    {
        cout << "--- The Maze Game ---" << endl << endl;

        cout << "Insira seu nome (max 4 caracteres): ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco

        cin >> name;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde claro

        name = name.substr(0, 4);

        cout << endl << name << ", este eh seu nome? s/n" << endl;
        op = getch();

        switch(op)
        {
        case 'S':
        case 's':
            startGame = true;

            cout << endl << "Pressione qualquer tecla para jogar..." << endl;
            getch();

            break;

        case 'N':
        case 'n':
            system("cls");

            break;

        default:
            cout << "Opcao invalida!" << endl;
            cout << "Tente novamente em 1s" << endl;

            Sleep(1000);
            system("cls");

            break;
        }
    }
    while(startGame == false);

    return name;
}

int main()
{
    Personagem p1;
    int x = 1, y = 3;
    char tecla;
    int time, oldTime, score;
    string name;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde claro

    Menu();
    system("cls");

    name = InsertName();
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco

    CONSOLE_CURSOR_INFO ConCurInf; // Este é o objeto que configura o cursor
    ConCurInf.dwSize = 10; // Este é o tamanho do cursor, que vai de 0% a 100%
    ConCurInf.bVisible = FALSE; // Este atributo o deixa visivel ou não
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);

    gotoxy(0,0);
    PrintMapa(); // Imprime o mapa

    p1.x = x, p1.y = y;
    Player(p1.x, p1.y); // Imprime o player

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde Claro

    for(int i = 3; i > 0; i--)  // Contagem regressiva
    {
        gotoxy(0, 20);
        cout << "Prepare-se: " << i;

        Sleep(1000);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco

    gotoxy(0, 20);
    cout << "                        ";

    struct timeval inicio, fim; // Estruturas para leitura do tempo pelo gettimeofsday
    long double tempo = 0.0; // Variavel para armazenar o tempo de execução.
    gettimeofday(&inicio, NULL); // Dispara um cronometro (pega o horário de inicio);

    while(true)
    {
        if(kbhit())
        {
            tecla = getch();
        }
        else
        {
            tecla = 0;
        }

        if(tecla == 'W' || tecla == 'A' || tecla == 'S' || tecla == 'D' || tecla == 'w' || tecla == 'a' || tecla == 's' || tecla == 'd' || oldTime != time)
        {
            p1.points -= 5; // Player perde pontos a cada movimento e a cada segundo

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Amarelo

            gotoxy(31, 1);
            cout << "                        ";
            gotoxy(31, 1);
            cout << "Points: " << p1.points; // Imprime os pontos na tela

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco

            /*gotoxy(31, 5);
            cout << "                        ";
            gotoxy(31, 5);
            cout << "x: " << p1.x << ", y: " << p1.y;*/ // Cordenadas
        }

        oldTime = time; // oldTime eh utilizado para saber se passou-se 1 segundo

        switch(tecla)
        {
        case 'W':
        case 'w':
            Delete(p1.x, p1.y);

            if(mapa[p1.y-1][p1.x] == ' ') // Colisão 'W'
            {
                p1.y--;
            }

            Player(p1.x, p1.y);

            break;

        case 'A':
        case 'a':
            Delete(p1.x, p1.y);

            if(mapa[p1.y][p1.x-1] == ' ') // Colisão 'A'
            {
                p1.x--;
            }

            Player(p1.x, p1.y);

            break;

        case 'S':
        case 's':
            Delete(p1.x, p1.y);

            if(mapa[p1.y+1][p1.x] == ' ') // Colisão 'S'
            {
                p1.y++;
            }

            Player(p1.x, p1.y);

            break;

        case 'D':
        case 'd':
            Delete(p1.x, p1.y);

            if(mapa[p1.y][p1.x+1] == ' ') // Colisão 'D'
            {
                p1.x++;
            }

            Player(p1.x, p1.y);

            break;
        }
        gettimeofday(&fim, NULL); // Para o cronometro (pega o horário de termino do seu trecho de codigo)
        tempo = ((fim.tv_sec + fim.tv_usec / 1000000.0) - (inicio.tv_sec + inicio.tv_usec / 1000000.0)) * 1.0;

        time = tempo; // Time recebe o valor de tempo como um inteiro

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Amarelo

        gotoxy(31, 3);
        cout << "Tempo: " << fixed << setprecision(2) << tempo << "s";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Branco

        if(p1.x == 27 && p1.y == 15) // Condicao para vitoria
        {
            score = (p1.points - time) * 2; // Sistema de "Score"

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde Claro

            gotoxy(6, 20);
            cout << "-- Game Over --";
            gotoxy(0, 21);
            cout << "Voce Ganhou!";
            gotoxy(0, 22);
            cout << "Score: " << score;

            SaveScore(name, score);

            gotoxy(0, 24);
            cout << "Seu score foi salvo na tabela!";

            gotoxy(0, 26);
            cout << "Pressione qualquer tecla para continuar...";
            getch();
            exit(0);
        }
        else if(p1.points <= 0) // Condicao para derrota
        {
            gotoxy(6, 20);
            cout << "-- Game Over --";
            gotoxy(0, 21);
            cout << "Voce perdeu! Seus pontos acabaram.";

            gotoxy(0, 23);
            cout << "Pressione qualquer tecla para continuar...";
            getch();
            exit(0);
        }
    }
}
