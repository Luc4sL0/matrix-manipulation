#include <stdio.h>
#include <string>
#include <time.h>
#include "matrixLib.h"

using namespace std;

char consoleImplementation(){
    char userChoice;
    printf("Bem vindo ao manipulador de matrizes!\n");
    printf("Selecione a opção que deseja executar com as matrizes presentes acima!");
    printf("MENU:\nA - Calcular transposta\nB - Somar as matrizes\nC - Multiplicar matrizes");
    printf("\nD - Calcular valor médio\n\nF - Sair\n");
    scanf("%c",&userChoice);
    return userChoice;
}
void showMatrix(matrixObj mA, char title){
    if(mA.matrixIsValid){
        printf("Matriz %c:\n", title);
        for (int i = 0; i < mA.rows; i++)
        {
            printf("|");
            for (int j = 0; j < mA.collumns; j++)
                printf("%4d", mA.content[i][j]);
            printf("|");
            printf("\n");
        }
        printf("\n");
    }
    else
        printf("Matriz %c é inválida.", title);
}
void generateMatrix(matrixObj *mA, int rows, int collumns){
    mA->rows = rows;
    mA->collumns = collumns;
    for (int i = 0; i < mA->rows; i++)
        for (int j = 0; j < mA->collumns; j++)
            mA->content[i][j] = 0 + rand() % 10;
}
int main(){
    srand(time(NULL));
    matrixObj matrix01, matrix02, matrixResult;
    
    char option;
    int insideOption;

    generateMatrix(&matrix01, 3, 3);
    generateMatrix(&matrix02, 3, 2);

    showMatrix(matrix01, '1');
    showMatrix(matrix02, '1');

    do
    {
        option = consoleImplementation();
        switch (option)
        {
            case 'A':
                printf("Selecione a matriz que você deseja usar.\n");
                printf("1 - Matriz 01\n2 - Matriz 02\n\n0 - Voltar");
                scanf("%d", &insideOption);
                switch (insideOption)
                {
                    case 1:
                        matrixResult = matrixTransposed(matrix01);
                        showMatrix(matrixResult, 'T');
                        break;
                    case 2:
                        matrixResult = matrixTransposed(matrix02);
                        showMatrix(matrixResult, 'T');
                        break;
                }
                break;
            case 'B':
                matrixResult = matrixSum(matrix01, matrix02);
                showMatrix(matrixResult, 'R');
                break;
            case 'C':
                matrixResult = matrixMultiplication(matrix01, matrix02);
                showMatrix(matrixResult, 'R');
                break;
            case 'D':
                printf("Selecione a matriz que você deseja usar.\n");
                printf("1 - Matriz 01\n2 - Matriz 02\n\n0 - Voltar");
                scanf("%d", &insideOption);
                switch (insideOption)
                {
                    case 1:
                        printf("O valor médio da matriz 01 é: %.2f!", matrixMediumVal(matrix01));
                        break;
                    case 2:
                        printf("O valor médio da matriz 02 é: %.2f!", matrixMediumVal(matrix02));
                        break;
                }
                break;
        }

    } while (option != 'F');
}