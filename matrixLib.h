/* 
 * File:   matrixLib.h
 * Author: Lucas Lopes Baroni(2024.1.08.017)
 *
 * Created on 17 de junho de 2024, 09:49
 */

#ifndef MATRIZLIB_H
#define MATRIZLIB_H

//Constantes

#define MAX 128

//Variáveis

typedef struct{
    int content[MAX][MAX];
    int rows, collumns;

    bool matrixIsNotValid;
} matrixObj;

/*
 * Retorna uma matriz transposta.
 * 
 * A matriz criada nessa função equivale a matriz 
 * transposta do argumento fornecido durante sua 
 * chamada.
 * 
 * @mA parametro1 matriz original.
 * @return retorna a matriz transposta.
 */
matrixObj matrixTransposed(matrixObj mA);

/*
 * Soma das matrizes.
 * 
 * A matriz criada nessa função equivale a soma  
 * das duas matrizes fornecidas nos argumentos 
 * durante sua chamada.
 * 
 * @mA parametro1 primeira matriz.
 * @mB parametro1 segunda matriz.
 * @return retorna a matriz soma.
 */
matrixObj matrixSum(matrixObj mA, matrixObj mB);

/*
 * Multiplicação das matrizes.
 * 
 * A matriz criada nessa função equivale a 
 * multiplicação das duas matrizes fornecidas 
 * nos argumentos durante sua chamada.
 * 
 * @mA parametro1 primeira matriz.
 * @mB parametro1 segunda matriz.
 * @return retorna a matriz produto.
 */
matrixObj matrixMultiplication(matrixObj mA, matrixObj mB);

/*
 * Valor médio da matriz.
 * 
 * Essa função retorna o valor flutuante equivalente 
 * a média dos valores da matriz fornecida no argumento 
 * durante sua chamada.
 * 
 * @mA parametro1 matriz.
 * @return retorna o valor númerico da média.
 */
float matrixMediumVal(matrixObj mA);

#endif
