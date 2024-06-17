/* 
 * File:   main.cpp
 * Author: Lucas Lopes Baroni(2024.1.08.017)
 *
 * Created on 17 de junho de 2024, 09:49
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <time.h>
#include <iostream>
#include "matrixLib.h"

using namespace std;

char consoleImplementation(){
    char userChoice;
    printf("Bem vindo ao manipulador de matrizes!\n");
    printf("Selecione a opção que deseja executar com as matrizes presentes acima!\n\n");
    printf("MENU:\nA - Calcular transposta\nB - Somar as matrizes\nC - Multiplicar matrizes");
    printf("\nD - Calcular valor médio\n\nF - Sair\n\n");
    do
    {
        printf("Insira a opção (somente as opções do menu são válidas): ");
        cin>>userChoice;
    }
    while(userChoice != 'A' && userChoice != 'B' && userChoice != 'C' && userChoice != 'D' && userChoice != 'F');
    return userChoice;
}
void showMatrix(matrixObj mA, char title){
    if(mA.matrixIsNotValid == false){
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
        printf("Matriz %c é inválida (indefinida).\n", title);
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
    int r1, c1, r2, c2, insideOption;
    char option;
    
    do {
        printf("Insira respectivamente o número de linhas e colunas da sua matriz 01 (separados por espaço): ");
        cin >> r1>>c1;
        printf("Insira respectivamente o número de linhas e colunas da sua matriz 02 (separados por espaço): ");
        cin >> r2>>c2;
    } while ((r1 < 0 || r1 > MAX) || (r2 < 0 || r2 > MAX) || (c1 < 0 || c1 > MAX) || (c2 < 0 || c2 > MAX));
    
    generateMatrix(&matrix01,r1, c1);
    generateMatrix(&matrix02, r2, c2);

    showMatrix(matrix01, '1');
    showMatrix(matrix02, '2');

    do
    {
        option = consoleImplementation();
        switch (option)
        {
            case 'A': //Calcula transposta.
                printf("Selecione a matriz que você deseja usar.\n");
                printf("1 - Matriz 01\n2 - Matriz 02\n\n0 - Voltar\n\n");
                printf("Insira sua opção: ");
                cin>>insideOption;
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
            case 'B': //Calcula a soma.
                matrixResult = matrixSum(matrix01, matrix02);
                showMatrix(matrixResult, 'R');
                break;
            case 'C': //Calcula a multiplicação.
                matrixResult = matrixMultiplication(matrix01, matrix02);
                showMatrix(matrixResult, 'R');
                break;
            case 'D': //Calcula o valor médio.
                printf("Selecione a matriz que você deseja usar.\n");
                printf("1 - Matriz 01\n2 - Matriz 02\n\n0 - Voltar");
                cin>>insideOption;
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
