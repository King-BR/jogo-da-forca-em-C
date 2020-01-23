/* 
 * Projeto de Linguagem de Progamação 1
 * Jogo da forca
 * Feito por Pedro e Fernando
 * Versão: 9.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

char magicword[30];
char dica[20];
int dificil;

int num_aleatorio();
int num_aleatorioAnimal();
int num_aleatorioLugar();
int num_aleatorioComida();
int num_aleatorioObjeto();
int num_aleatorioCor();
void jogar();
void novojogo();
void dificuldade();
void word();
void wordAnimal();
void wordLugar();
void wordComida();
void wordObjeto();
void wordCor();
void adc();
void adcAnimal();
void adcLugar();
void adcComida();
void adcObjeto();
void adcCor();
void pause(float delay1);
void caveira_fechada();
void caveira_aberta();
void animacao_caveira();
void tela_de_carregamento();
void forca();
void forca_cabeca();
void forca_rosto();
void forca_tronco();
void forca_bracos();
void forca_pernas();

int main() {

    setlocale(LC_ALL, "portuguese-brazilian");

    system("cls");
    tela_de_carregamento ();
    system("cls");

    jogar();

    return 0;
}

void jogar() {
    int err = 0, aux = 0, venceu, Q = 0, I;
    char letra;
    char letras[20];

    dificuldade();

    if (dificil == -1) {
        printf("Ate a proxima vez!!\n\n");
        return;
    }

    int i, j;

    i = strlen(magicword);
    i--;

    char palavra[i];

    for (j = 0; j <= i; j++) {
        palavra[j] = '_';
    }


    do{
        fflush(stdin);
        venceu = 1;
        printf("/*********************************\\  \n");
        printf("|          JOGO DA FORCA          |   \n");
        printf("\\*********************************/  \n\n\n");

        if(err == 0){
            forca();
        }else if(err == 1){
            forca_cabeca();
        }else if(err == 2){
            forca_rosto();
        }else if(err == 3){
            forca_tronco();
        }else if(err == 4){
            forca_bracos();
        }else if(err == 5){
            forca_pernas();
        }

        printf("\n\n");

        for (j = 0; j < i; j++) {
            printf("%c ",palavra[j]);
        }

        if (strlen(dica) > 0 && dificil == 0) {
            printf("\n\ndica: %s",dica);
        }

        if (Q != 0) {
            printf("\n\nletras usadas: ");

            for (I = 0; I < Q; I++)
            {
                printf("%c ",letras[I]);
            }
            
        }
        
        //printf("\n\nhackzinho: %s", magicword);

        printf("\n\n\nDigite uma letra: ");
        fflush(stdin);
        scanf("%c",&letra);

        int auxl = 0;
        for (int J = 0; J < Q; J++) {
            if (letras[J] == letra) {
                auxl = 1;
            }
        }
        
        if (auxl != 1) {
            letras[Q] = letra;
            Q++;

        for (j = 0; j < i; j++) {
            

            if (letra == magicword[j]) {
                palavra[j] = letra;
                aux = 1;
            }
            
            //printf("\n%d",aux);
        }
        
        //system("pause");
        
        if(aux == 0){
            err++;
        }else{
            aux = 0;
        }

        //printf("\n%d",aux);
        //printf("\n%d",err);
        //system("pause");
        
        for (j = 0; j < i; j++) {
            if ('_' == palavra[j]) {
                venceu = 0;
            }
            //printf("\n%d",aux);
        }
        if (err == 5) {
            system("cls");
            forca_pernas();
            pause(0.2);
            system("cls");
            animacao_caveira();
            system("pause");
            break;
        }else if(venceu == 1){
            system("cls");

            printf("\n\n\n");
            printf("       Voce ganhou!     \n");
            printf("       ___________      \n");
            printf("      '._==_==_=_.'     \n");
            printf("      .-\\:      /-.    \n");
            printf("     | (|:.     |) |    \n");
            printf("      '-|:.     |-'     \n");
            printf("        \\::.    /      \n");
            printf("         '::. .'        \n");
            printf("           ) (          \n");
            printf("         _.' '._        \n");
            printf("        '-------'       \n\n");
            printf("\n\n");
            break;
        }
        
        
        } else {
            printf("\n\nVoce ja digitou essa letra\ntente novamente\n");
            system("pause");
        }
        system("cls");
    }while (err != 5);

    adc();

    return;
}

int num_aleatorioAnimal() {

    int i, numlinha = 0;
    int x;
    FILE *num = fopen("animal.txt", "r");

    do {
        x = fgetc(num);
        if (x == '\n') {
            numlinha++;
        }
    } while (x != EOF);

    fclose(num);
    srand(time(NULL));
    
    i = (rand() % numlinha);

    if (i != 0) {
        return i;
    } else {
        num_aleatorioAnimal();
    }
    return i;
}

int num_aleatorioLugar() {

    int i, numlinha = 0;
    int x;
    FILE *num = fopen("lugar.txt", "r");

    do {
        x = fgetc(num);
        if (x == '\n') {
            numlinha++;
        }
    } while (x != EOF);

    fclose(num);
    srand(time(NULL));

    i = (rand() % numlinha);

    if (i != 0) {
        return i;
    } else {
        num_aleatorioLugar();
    }
    return i;
}

int num_aleatorioComida() {

    int i, numlinha = 0;
    int x;
    FILE *num = fopen("comida.txt", "r");

    do
    {
        x = fgetc(num);
        if (x == '\n')
        {
            numlinha++;
        }
    } while (x != EOF);

    fclose(num);
    srand(time(NULL));

    i = (rand() % numlinha);

    if (i != 0)
    {
        return i;
    }
    else
    {
        num_aleatorioComida();
    }
    return i;
}

int num_aleatorioObjeto() {

    int i, numlinha = 0;
    int x;
    FILE *num = fopen("objeto.txt", "r");

    do
    {
        x = fgetc(num);
        if (x == '\n')
        {
            numlinha++;
        }
    } while (x != EOF);

    fclose(num);
    srand(time(NULL));

    i = (rand() % numlinha);

    if (i != 0)
    {
        return i;
    }
    else
    {
        num_aleatorioObjeto();
    }
    return i;
}

int num_aleatorioCor() {

    int i, numlinha = 0;
    int x;
    FILE *num = fopen("cor.txt", "r");

    do
    {
        x = fgetc(num);
        if (x == '\n')
        {
            numlinha++;
        }
    } while (x != EOF);

    fclose(num);
    srand(time(NULL));

    i = (rand() % numlinha);

    if (i != 0)
    {
        return i;
    }
    else
    {
        num_aleatorioCor();
    }
    return i;
}

int num_aleatorio() {
    int i, numlinha = 0;
    int x;
    FILE *num = fopen("Test.txt", "r");
    do {
        x = fgetc(num);
        if (x == '\n') {
            numlinha++;
        }
    } while (x != EOF);
    fclose(num);
    srand(time(NULL));
    i = (rand() % numlinha);
    if (i != 0) {
        return i;
    } else {
        num_aleatorio();
    }
    return i;
}

void dificuldade() {
    int dif,i = 0;

    printf("Qual a dificuldade desejada?\n\n1) Facil (com dicas)\n2) Dificil (sem dicas)\n3) Encerrar\n");
    scanf("%d",&dif);

    system("cls");

    switch (dif) {
        case 1: {
            dificil = 0;
            do {
                srand(time(NULL));
                i = (rand() % 5);
            } while (i == 0);

            switch (i) {
                case 1: {
                    wordAnimal();
                    break;
                }
                case 2: {
                    wordComida();
                    break;
                }
                case 3: {
                    wordCor();
                    break;
                }
                case 4: {
                    wordLugar();
                    break;
                }
                case 5: {
                    wordObjeto();
                }
            }
            break;
        }
        case 2: {
            dificil = 1;
            word();
            break;
        }
        case 3: {
            dificil = -1;
            return;
        }
        default: {
            printf("\nVoce digitou algo errado! Tente novamente\n");
            system("pause");
            system("cls");
            dificuldade();
            break;
        }
    }
    return;
}

void word() {
    int x = num_aleatorio();
    char palavra[50];
    FILE *ar = fopen("Test.txt", "r");
    int i = 0;
    while (i < x) {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    strcpy(magicword, palavra);
}

void wordAnimal()
{
    int x = num_aleatorioAnimal();
    char palavra[50];
    FILE *ar = fopen("animal.txt", "r");
    int i = 0;
    while (i < x)
    {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    
    if (strlen(palavra) > 0) {
        strcpy(magicword, palavra);
        strcpy(dica, "animal");
    }
}

void wordLugar()
{
    int x = num_aleatorioAnimal();
    char palavra[50];
    FILE *ar = fopen("lugar.txt", "r");
    int i = 0;
    while (i < x)
    {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);

    if (strlen(palavra) > 0) {
        strcpy(magicword, palavra);
        strcpy(dica, "lugar");
    }
}

void wordComida()
{
    int x = num_aleatorioComida();
    char palavra[50];
    FILE *ar = fopen("comida.txt", "r");
    int i = 0;
    while (i < x)
    {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    
    if (strlen(palavra) > 0) {
        strcpy(magicword, palavra);
        strcpy(dica, "comida");
    }
}

void wordObjeto()
{
    int x = num_aleatorioObjeto();
    char palavra[50];
    FILE *ar = fopen("objeto.txt", "r");
    int i = 0;
    while (i < x)
    {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    
    if (strlen(palavra) > 0) {
        strcpy(magicword, palavra);
        strcpy(dica, "objeto");
    }
}

void wordCor()
{
    int x = num_aleatorioCor();
    char palavra[50];
    FILE *ar = fopen("cor.txt", "r");
    int i = 0;
    while (i < x)
    {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    
    if (strlen(palavra) > 0) {
        strcpy(magicword, palavra);
        strcpy(dica, "cor");
    }
}

void adc() {
    char quer;
    int categoria;

    fflush(stdin);
    printf("Voce deseja adicionar uma nova palavra no jogo?(s/n): ");
    scanf("%c", &quer);
    if (quer == 's') {
        printf("Em qual categoria voce deseja adicionar a nova palavra?\n1) Animal\n2) Lugar\n3) Comida\n4) Objeto\n5) Cor\n");
        scanf("%d",&categoria);

        switch (categoria) {
            case 1: {
                adcAnimal();
                break;
            }
            case 2: {
                adcLugar();
                break;
            }
            case 3: {
                adcComida();
                break;
            }
            case 4: {
                adcObjeto();
                break;
            }
            case 5: {
                adcCor();
                break;
            }
        }
    }

    novojogo();
}

/*
    char novap[50];
    FILE *add = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);
 */

void adcAnimal() {
    char novap[50];
    FILE *add = fopen("animal.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);

    FILE *add2 = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add2, "\n%s", novap);
    fclose(add2);
}

void adcLugar() {
    char novap[50];
    FILE *add = fopen("lugar.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);

    FILE *add2 = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add2, "\n%s", novap);
    fclose(add2);
}

void adcComida() {
    char novap[50];
    FILE *add = fopen("comida.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);

    FILE *add2 = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add2, "\n%s", novap);
    fclose(add2);
}

void adcObjeto() {
    char novap[50];
    FILE *add = fopen("objeto.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);

    FILE *add2 = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add2, "\n%s", novap);
    fclose(add2);
}

void adcCor() {
    char novap[50];
    FILE *add = fopen("cor.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);

    FILE *add2 = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add2, "\n%s", novap);
    fclose(add2);
}

void pause(float delay1) {
    if (delay1 < 0.001) return;

    float inst1 = 0, inst2 = 0;
    inst1 = (float)clock() / (float)CLOCKS_PER_SEC;

    while (inst2 - inst1 < delay1) {
        inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
    }

    return;
}

void caveira_fechada() {
    printf("        Voce perdeu!       \n");
    printf("                           \n");
    printf("       ---0000000---       \n");
    printf("    -00000000000000000-    \n");
    printf("   |0000000000000000000|   \n");
    printf("   |0000000000000000000|   \n");
    printf("  0|0000000000000000000|0  \n");
    printf("  00|00000000000000000|00  \n");
    printf("  00|0     00000     0|00  \n");
    printf("   0|       000       |0   \n");
    printf("   0|      00_00      |0   \n");
    printf("    |0000000___0000000|    \n");
    printf("   000___000-_-000___000   \n");
    printf("      |___0000000___|      \n");
    printf("     00__TTTTTTTTT__00     \n");
    printf("     000-TTTTTTTTT-000     \n");
    printf("      000TTTTTTTTT000      \n");
    printf("        00000000000        \n");
    printf("\n\nA palavra era: %s\n\n", magicword);
}

void caveira_aberta() {
    printf("        Voce perdeu!       \n");
    printf("                           \n");
    printf("       ---0000000---       \n");
    printf("    -00000000000000000-    \n");
    printf("   |0000000000000000000|   \n");
    printf("   |0000000000000000000|   \n");
    printf("  0|0000000000000000000|0  \n");
    printf("  00|00000000000000000|00  \n");
    printf("  00|0     00000     0|00  \n");
    printf("   0|       000       |0   \n");
    printf("   0|      00_00      |0   \n");
    printf("    |0000000___0000000|    \n");
    printf("   000___000-_-000___000   \n");
    printf("      |___0000000___|      \n");
    printf("     00__TTTTTTTTT__00     \n");
    printf("     000-         -000     \n");
    printf("      000TTTTTTTTT000      \n");
    printf("        00000000000        \n");
    printf("\n\nA palavra era: %s\n\n", magicword);
}

void animacao_caveira() {
    caveira_fechada();
    pause(0.5);
    system("cls");
    caveira_aberta();
    pause(0.5);
    system("cls");
    caveira_fechada();
    pause(0.5);
    system("cls");
    caveira_aberta();
    pause(0.5);
    system("cls");
    caveira_fechada();
}

void forca()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_cabeca()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (   )  \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_rosto()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_tronco()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                  |    \n");
    printf("  |                  |    \n");
    printf("  |                  |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_bracos()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                 /|\\  \n");
    printf("  |                / | \\ \n");
    printf("  |                  |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_pernas()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                 /|\\  \n");
    printf("  |                / | \\ \n");
    printf("  |                  |    \n");
    printf("  |                 / \\  \n");
    printf("  |                /   \\ \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void tela_de_carregamento() {
    int i;
    printf("Loading program...\n");
    for (i = 0; i < 25; i++) {
        pause(0.05);
        printf("=");
    }
    printf("\n\nFinishing installation");
    pause(0.3);
    printf(".");
    pause(0.3);
    printf(".");
    pause(0.3);
    printf(".\n\n");
    pause(0.3);
    printf("Jogo feito por Pedro e Fernando\n\n");
    pause(2);
}

void novojogo() {
    char quer;

    fflush(stdin);
    printf("Quer jogar novamente? (s/n): ");
    scanf("%c", &quer);
    if (quer == 's')
    {
        system("cls");
        jogar();
    }
}