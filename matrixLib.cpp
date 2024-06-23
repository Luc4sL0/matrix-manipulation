/* 
 * File:   matrixLib.cpp
 * Author: Lucas Lopes Baroni
 *
 * Created on 17 de junho de 2024, 09:49
 */

#include <stdio.h>
#include <cmath>
#include "matrixLib.h"

#define DEBUG //printf //Remova o comentário ao lado para obter logs das funções.

void generateMatrix(matrixObj *mA, int rows, int collumns){
    mA->rows = rows;
    mA->collumns = collumns;
    for (int i = 0; i < mA->rows; i++)
        for (int j = 0; j < mA->collumns; j++)
            mA->content[i][j] = 0 + rand() % 10;
}
void showMatrix(matrixObj mA, char title){
    if(mA.matrixIsNotValid == false){
        printf("Matriz %c:\n", title);
        for (int i = 0; i < mA.rows; i++){
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

void matrixCopyPaste(matrixObj mC, matrixObj *mP){
    mP->collumns = mC.collumns;
    mP->rows = mC.rows;
    mP->matrixIsNotValid = mC.matrixIsNotValid;
    for(int i = 0; i < mP->rows; i++)
        for (int j = 0; j < mP->collumns; j++)
            mP->content[i][j] = mC.content[j][i];
}
matrixObj matrixTransposed(matrixObj mA){
    matrixObj mT;
    mT.matrixIsNotValid = mA.matrixIsNotValid;
    mT.rows = mA.collumns;
    mT.collumns = mA.rows;
    for(int i = 0; i < mT.rows; i++)
        for (int j = 0; j < mT.collumns; j++)
            mT.content[i][j] = mA.content[j][i];
    return mT;
}
matrixObj matrixSum(matrixObj mA, matrixObj mB){
    matrixObj mR;
    mR.matrixIsNotValid = mA.matrixIsNotValid || mB.matrixIsNotValid;
    if(mA.rows == mB.rows && mA.collumns == mB.collumns){
        mR.rows = mA.rows;
        mR.collumns = mA.collumns;
        for (int i = 0; i < mR.rows; i++)
            for (int j = 0; j < mR.collumns; j++)
                mR.content[i][j] = mA.content[i][j] + mB.content[i][j];
        return mR;
    }
    else{
        mR.matrixIsNotValid = true;
        DEBUG("ERRO: mA e mB não possuem o mesmo número de linhas e colunas.\n");
    }
    return mR;
}
matrixObj matrixMultiplication(matrixObj mA, matrixObj mB){
    int aux;
    matrixObj mR;
    mR.matrixIsNotValid = mA.matrixIsNotValid || mB.matrixIsNotValid;
    if(mA.collumns == mB.rows){
        mR.rows = mA.rows;
        mR.collumns = mB.collumns;
        for (int i = 0; i < mA.rows; i++)
            for (int j = 0; j < mB.collumns; j++){
                for (int x = 0; x < mB.rows; x++)
                    aux += mA.content[i][x] * mB.content[x][j];
                mR.content[i][j] = aux;
                aux = 0;
            }
    }
    else{
        mR.matrixIsNotValid = true;
        DEBUG("ERRO: mA e mB não possuem o mesmo número de colunas e linhas, respectivamente.\n");
    }
    return mR;
}
float matrixMediumVal(matrixObj mA) {
    float valTotal = 0;
    if (!mA.matrixIsNotValid) {
        for (int i = 0; i < mA.rows; i++)
            for (int j = 0; j < mA.rows; j++)
                valTotal += mA.content[i][j];
    }
    return valTotal / (mA.rows * mA.collumns);
}
