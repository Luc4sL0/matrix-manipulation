#include <stdio.h>
#include "matrixLib.h"

#define DEBUG printf

matrixObj matrixTransposed(matrixObj mA){
    matrixObj mT;
    mT.rows = mA.rows;
    mT.collumns = mA.collumns;
    for(int i = 0; i < mT.rows; i++)
        for (int j = 0; j < mT.collumns; j++)
            mT.content[i][j] = mA.content[j][i];
    return mT;
}
matrixObj matrixSum(matrixObj mA, matrixObj mB){
    matrixObj mR;
    if(mA.rows == mB.rows && mA.collumns == mB.collumns){
        mR.rows = mA.rows;
        mR.collumns = mA.collumns;
        for (int i = 0; i < mR.rows; i++)
            for (int j = 0; j < mR.collumns; j++)
                mR.content[i][j] = mA.content[i][j] + mB.content[i][j];
        return mR;
    }
    else{
        mR.matrixIsValid = false;
        DEBUG("ERRO: mA e mB não possuem o mesmo número de linhas e colunas.\n");
    }
    return mR;
}
matrixObj matrixMultiplication(matrixObj mA, matrixObj mB){
    int aux;
    matrixObj mR;
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
        mR.matrixIsValid = false;
        DEBUG("ERRO: mA e mB não possuem o mesmo número de colunas e linhas, respectivamente.\n");
    }
    return mR;
}
float matrixMediumVal(matrixObj mA){
    float valTotal = 0;
    for (int i = 0; i < mA.rows; i++)
        for (int j = 0; j < mA.rows; j++)
            valTotal += mA.content[i][j];
    return valTotal/(mA.rows * mA.collumns);
}
