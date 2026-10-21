#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <sys/time.h>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x,y
    });
}

void PrintLinha(int x, int y)
{
    SetConsoleTextAttribute(hConsole, 15);

    gotoxy(x, y);
    cout << "ßßßßßßßßßßßßßßßßßßßßßßßßß";
}

void PrintLetra(int x, int y, int maxLinha, char spawnLetra)
{
    if(y >= 0 && y < maxLinha / 2 || y > maxLinha)
    {
        SetConsoleTextAttribute(hConsole, 12);
    }
    else if(y >= maxLinha / 2 && y < maxLinha)
    {
        SetConsoleTextAttribute(hConsole, 14);
    }
    else if(y == maxLinha)
    {
        SetConsoleTextAttribute(hConsole, 2);
    }

    gotoxy(x, y);
    cout << spawnLetra;

    SetConsoleTextAttribute(hConsole, 15);
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

    tabelaScores << name << "             " << score << endl;

    tabelaScores.close();
}

void PrintScoreboard()
{
    string linha;
    ifstream scoreboard;

    SetConsoleTextAttribute(hConsole, 14);

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

void SaveAcertos(int fase, int acertos, bool endGame)
{
    ofstream tabelaAcertos;

    if(endGame == true)
    {
        tabelaAcertos.open("acertos.txt", ios::trunc);

        tabelaAcertos.close();
    }
    else
    {
        tabelaAcertos.open("acertos.txt", ios::app);

        tabelaAcertos << "Fase " << fase << ": " << acertos << " acertos" << endl;

        tabelaAcertos.close();
    }
}

void PrintAcertos()
{
    string linha;
    ifstream acertosTabela;

    acertosTabela.open("acertos.txt");

    if(acertosTabela.is_open())
    {
        while(getline(acertosTabela, linha))
        {
            cout << linha << endl;
        }
        acertosTabela.close();
    }
    else
    {
        cout << "Nao foi possivel imprimir a tabela de acertos";
    }
}

void Menu()
{
    int menu;
    bool inMenu = true;

    SetConsoleTextAttribute(hConsole, 10);

    do // Menu
    {
        system("cls");

        cout << "--- Datilografar Hero ---" << endl << endl;

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

            SetConsoleTextAttribute(hConsole, 10);

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

    SetConsoleTextAttribute(hConsole, 10);

    do // Escolha de nome para entrar no placar
    {
        cout << "--- Datilografar Hero ---" << endl << endl;

        cout << "Insira seu nome (max 4 caracteres): ";

        SetConsoleTextAttribute(hConsole, 15);

        cin >> name;

        SetConsoleTextAttribute(hConsole, 10);

        if(name.size() < 4)
        {
            cout << "Seu nome deve conter 4 caracteres!" << endl << endl;

            op = 0;
        }
        else
        {
            name = name.substr(0, 4);

            cout << endl << name << ", este eh seu nome? s/n" << endl;

            op = getch();
        }

        switch(op)
        {
        case 'S':
        case 's':
            startGame = true;

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
    srand(time(NULL));

    int positionsX = 4, x[positionsX] = {3, 6, 9, 12}, y;
    int maxLetras = 21, maxLinha = 10;
    int minAcertos = 10, acertos = 0, acertosTotal = 0, fase = 1, score = 0;
    int letraAtual = 0;
    int velocidade = 300;

    char spawnLetra;
    char tecla;

    bool nextLeter;
    bool endGame;
    bool inMenu = true;

    string name;

    CONSOLE_CURSOR_INFO ConCurInf; // Este é o objeto que configura o cursor
    ConCurInf.dwSize = 10; // Este é o tamanho do cursor, que vai de 0% a 100%
    ConCurInf.bVisible = false; // Este atributo o deixa visivel ou não
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);

    struct timeval inicio, fim; // Estruturas para leitura do tempo pelo gettimeofsday
    long double tempo = 0.0; // Variavel para armazenar o tempo de execução.
    gettimeofday(&inicio, NULL); // Dispara um cronometro (pega o horário de inicio);

    while(true)
    {
        if(inMenu == true)
        {
            y = 0;
            acertos = 0;
            acertosTotal = 0;
            fase = 1;
            letraAtual = 0;
            velocidade = 300;

            nextLeter = true;
            endGame = false;

            Menu();
            system("cls");

            name = InsertName();
            system("cls");

            tempo = 0.0; // Variavel para armazenar o tempo de execução.
            gettimeofday(&inicio, NULL); // Dispara um cronometro (pega o horário de inicio);

            SetConsoleTextAttribute(hConsole, 15);

            gotoxy(30, 4);
            cout << "Pontos: 0";

            inMenu = false;
        }

        if(kbhit())
        {
            tecla = getch();
        }
        else
        {
            tecla = 0;
        }

        if(letraAtual <= maxLetras && nextLeter == true)
        {
            y = 0;
            letraAtual++;

            PrintLinha(1, maxLinha);

            spawnLetra = rand()%26+97;
            positionsX = rand()%4;

            PrintLetra(x[positionsX], y, maxLinha, spawnLetra);

            nextLeter = false;
        }
        else
        {
            Delete(x[positionsX], y);

            y++;

            PrintLetra(x[positionsX], y, maxLinha, spawnLetra);

            Sleep(velocidade);
        }

        if(tecla == spawnLetra && y == 10)
        {
            acertos++;
            acertosTotal++;

            gotoxy(30, 4);
            cout << "Pontos: " << acertos;

            nextLeter = true;
        }
        else if(tecla > 0 && tecla != spawnLetra || y > 10)
        {
            Delete(x[positionsX], y);

            nextLeter = true;

            y = 0;
        }

        gettimeofday(&fim, NULL);// Para o cronometro (pega o horário de termino do seu trecho de codigo)
        tempo = ((fim.tv_sec + fim.tv_usec / 1000000.0) - (inicio.tv_sec + inicio.tv_usec / 1000000.0)) * 1.0;

        gotoxy(30, 2);
        cout << "Time: " << fixed << setprecision(2) << tempo;

        if(acertos >= minAcertos && letraAtual >= maxLetras)
        {
            SetConsoleTextAttribute(hConsole, 10);

            gotoxy(0, 12);
            cout << "Parabens! Voce acertou " << acertos << " letras" << endl << endl;

            SaveAcertos(fase, acertos, endGame);

            cout << "Aperte qualquer tecla para a proxima fase...";

            getch();

            acertos = 0;
            letraAtual = 0;

            fase++;
            velocidade -= 50;

            system("cls");

            nextLeter = true;
        }
        else if(acertos < minAcertos && letraAtual >= maxLetras)
        {
            SetConsoleTextAttribute(hConsole, 10);

            gotoxy(0, 12);
            cout << "--- GAME OVER ---" << endl << endl;

            SaveAcertos(fase, acertos, endGame); // Imprime os acertos de cada fase

            PrintAcertos();

            endGame = true;

            SaveAcertos(fase, acertos, endGame); // Limpa o arquivo de acertos

            score = (acertosTotal * 10) / ((int)tempo - 20); // Sistema de score

            cout << endl << "Score: " << score << endl << endl;

            SaveScore(name, score);

            cout << "Aperte qualquer tecla para retornar ao menu...";

            getch();

            inMenu = true;
        }
    }
    return 0;
}
