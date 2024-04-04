/*
 * Lightweight Matrix Library (LML)
 * File: lml.h
 * Author: James Bray
 *
 * This library provides a collection of functions for efficient manipulation
 * and operation on matrices. The library is designed for embedded systems and
 * offers functionality for generating matrices, retrieving data, performing
 * matrix operations, editing matrices, and various miscellaneous functions.
 * 
 * For more detailed documentation, see the README in the following repo:
 *      https://github.com/James-Bray19/Lightweight-Matrix-Library
 * 
 * Any contributions or issues should also be posted there.
 */

#ifndef LIGHTWEIGHTMATRIXLIBRARY_H
#define LIGHTWEIGHTMATRIXLIBRARY_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;



// --------------- Generating Matrices ---------------

// returns a matrix filled with zeros of size rows x cols
// params: rows - number of rows, cols - number of columns
Matrix *zeros(int rows, int cols);

// returns a matrix filled with ones of size rows x cols
// params: rows - number of rows, cols - number of columns
Matrix *ones(int rows, int cols);

// returns an identity matrix of size size x size
// params: size - size of the identity matrix
Matrix *identity(int size);

// returns a matrix filled with random values of size rows x cols
// params: rows - number of rows, cols - number of columns
Matrix *random(int rows, int cols);

// creates a matrix from a 2D array
// params: rows - number of rows, cols - number of columns, array - input array
Matrix *matrix_from_array(int rows, int cols, double array[rows][cols]);



// --------------- Retrieving Data ---------------

// returns the specified row of the matrix
// params: mat - input matrix, row - row index
Matrix *get_row(Matrix *mat, int row);

// returns the specified column of the matrix
// params: mat - input matrix, col - column index
Matrix *get_col(Matrix *mat, int col);

// creates a copy of the input matrix
// params: mat - input matrix
Matrix *copy(Matrix *mat);

// returns the lower triangular matrix of the input matrix
// params: mat - input matrix
Matrix *get_lower(Matrix *mat);

// returns the upper triangular matrix of the input matrix
// params: mat - input matrix
Matrix *get_upper(Matrix *mat);

// returns a submatrix of the input matrix
// params: mat - input matrix, row - starting row index, col - starting column index, rows - number of rows, cols - number of columns
Matrix *get_submatrix(Matrix *mat, int row, int col, int rows, int cols);



// --------------- Matrix Operations ---------------

// returns the determinant of the input matrix
// params: mat - input matrix
double det(Matrix *mat);

// returns the result of element-wise addition of two matrices
// params: mat1 - first matrix, mat2 - second matrix
Matrix *add(Matrix *mat1, Matrix *mat2);

// returns the result of matrix multiplication of two matrices
// params: mat1 - first matrix, mat2 - second matrix
Matrix *multiply(Matrix *mat1, Matrix *mat2);

// returns the transpose of the input matrix
// params: mat - input matrix
Matrix *transposed(Matrix *mat);

// Matrix *normalised(Matrix *mat);

// Matrix *normalised_rows(Matrix *mat);

// Matrix *normalised_cols(Matrix *mat);

// Matrix *QR_decompose(Matrix *mat, Matrix **Q, Matrix **R);

// decomposes the input matrix into Lower and Upper triangular matrices
// params: mat - input matrix, Q - output Lower triangular matrix, R - output Upper triangular matrix
Matrix *QR_decompose(Matrix *mat, Matrix **Q, Matrix **R);

// decomposes the input matrix into Lower and Upper triangular matrices
// params: mat - input matrix, L - output Lower triangular matrix, U - output Upper triangular matrix
Matrix *LU_decompose(Matrix *mat, Matrix **L, Matrix **U);

// solves a system of linear equations represented by matrices
// params: mat1 - coefficient matrix, mat2 - constant matrix
Matrix *solve(Matrix *mat1, Matrix *mat2);

// returns the inverse of the input matrix
// params: mat - input matrix
Matrix *inverse(Matrix *mat);



// --------------- Matrix Editing ---------------

// scales the matrix by a scalar value
// params: mat - input matrix, scalar - scalar value
void scale(Matrix *mat, double scalar);

// shifts the matrix by adding a scalar value to each element
// params: mat - input matrix, scalar - scalar value
void shift(Matrix *mat, double scalar);

// sets the values of a specific row in the matrix
// params: mat - input matrix, row_index - row index, row_values - matrix of row values
void set_row(Matrix *mat, int row_index, Matrix *row_values);

// sets the values of a specific column in the matrix
// params: mat - input matrix, col_index - column index, col_values - matrix of column values
void set_col(Matrix *mat, int col_index, Matrix *col_values);

// removes a row from the matrix
// params: mat - input matrix, row - index of row to remove
void remove_row(Matrix *mat, int row);

// removes column from the matrix
// params: mat - input matrix, col - index of column to remove
void remove_col(Matrix *mat, int col);

// inserts a new row with the provided values at the specified row index
// params: mat - destination matrix, row_index - row index, row_values - array of row values
void insert_row(Matrix *mat, int row, Matrix *row_values);

// inserts a new column with the provided values at the specified column index
// params: mat - destination matrix, col_index - column index, col_values - array of column values
void insert_col(Matrix *mat, int col, Matrix *col_values);

// appends rows from mat2 to mat1
// params: mat1 - destination matrix, mat2 - source matrix
void append_rows(Matrix *mat1, Matrix *mat2);

// appends columns from mat2 to mat1
// params: mat1 - destination matrix, mat2 - source matrix
void append_cols(Matrix *mat1, Matrix *mat2);

// applies a function element-wise to the matrix
// params: mat - input matrix, function - function pointer to apply
void map(Matrix *mat, double (*function)(double));



// --------------- Miscellaneous Functions ---------------

// displays the content of the matrix
// params: mat - input matrix
void display(Matrix *mat);

// releases memory allocated for the matrix
// params: mat - input matrix
void release(Matrix *mat);

#endif /* LIGHTWEIGHTMATRIXLIBRARY_H */