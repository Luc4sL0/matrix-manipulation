#ifndef MATRIZLIB_H
#define MATRIZLIB_H

#define MAX 128

typedef struct{
    int content[MAX][MAX];
    int rows, collumns;

    bool matrixIsNotValid;
} matrixObj;

matrixObj matrixTransposed(matrixObj mA);
matrixObj matrixSum(matrixObj mA, matrixObj mB);
matrixObj matrixMultiplication(matrixObj mA, matrixObj mB);
float matrixMediumVal(matrixObj mA);

#endif