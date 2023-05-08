/**
 * A simple program to solve matrices.
 * By Chenyi Wang
 * 5/7/2023
 */

#include <stdio.h>

const int MAX_SIZE = 10; // Constant to cap matrix at 10 x 10

// Declared prototypes
int setSelection(void);
int setDim(int);
void printWelcome(void);
void setMatrix(double[MAX_SIZE][MAX_SIZE], int, int);
void add(double[][MAX_SIZE], double[][MAX_SIZE], int, int);
void subtract(double[][MAX_SIZE], double[][MAX_SIZE], int, int);
void multiply(double[][MAX_SIZE], double[][MAX_SIZE], int, int);
void scalar(double[][MAX_SIZE], int, int, double);
void transpose(double[][MAX_SIZE], int, int);
void runMatrixCalc(void);
void getFunction(int, double[MAX_SIZE][MAX_SIZE], double[MAX_SIZE][MAX_SIZE], int, int, int, int);
void printMatrix(double[MAX_SIZE][MAX_SIZE], int, int);

/**
 * Main method to execute calculator.
 * pre: none
 * post: print out calculation
 */
int main(void)
{
    int cont = 0;
    printWelcome();
    while (cont == 0)
    {
        runMatrixCalc();
        printf("Would you like to calculate another matrix? Yes(0) / No (1): ");
        scanf("%d", &cont);
    }
}

/**
 * Main body of the calculator.
 * pre: none
 * post: executes other functions
 */
void runMatrixCalc(void)
{
    int selection = setSelection();
    int correct = 0;

    printf("\nEnter Left Side Matrix:");
    int leftRows = setDim(0), leftCols = setDim(1), rightRows, rightCols;
    if (selection > 0 && selection < 4)
    {
        printf("\nEnter Right Side Matrix:");
        rightRows = setDim(0), rightCols = setDim(1);
        if ((selection == 1 || selection == 2) &&
            (leftRows != rightRows || leftCols != rightCols))
        {
            correct++;
        }
        else if ((selection == 3) && (leftCols != rightRows))
        {
            correct++;
        }
    }

    if (correct == 0)
    {
        double leftMatrix[MAX_SIZE][MAX_SIZE];
        double rightMatrix[MAX_SIZE][MAX_SIZE];
        setMatrix(leftMatrix, leftRows, leftCols);
        setMatrix(rightMatrix, rightRows, rightCols);
        getFunction(selection, leftMatrix, rightMatrix, leftRows, leftCols, rightRows, rightCols);
    }
    else
    {
        printf("\n *ERROR* Incompatible Dimensions\n");
    }
}

/**
 * Compilation of different computation functions.
 * pre: none
 * post: runs the function based on selection
 * @param selection the function to perform
 * @param left the left side matrix
 * @param right the right side matrix
 * @param leftRows number of rows in left matrix
 * @param leftCols number of columns in left matrix
 * @param rightRows number of rows in right matrix
 * @param rightCols number of columns in right matrix
 */
void getFunction(int selection, double left[MAX_SIZE][MAX_SIZE],
                 double right[MAX_SIZE][MAX_SIZE], int leftRows, int leftCols, int rightRows, int rightCols)
{
    double scale;
    if (selection == 4)
    {
        printf("Enter the scalar multiple: ");
        scanf("%lf", &scale);
    }
    switch (selection)
    {
    case 1:
        add(left, right, leftRows, leftCols);
        break;
    case 2:
        subtract(left, right, leftRows, leftCols);
        break;
    case 3:
        multiply(left, right, leftRows, rightCols);
        break;
    case 4:
        scalar(left, leftRows, leftCols, scale);
        break;
    case 5:
        transpose(left, leftRows, leftCols);
        break;
    }
}

/**
 * Prints the computed matrix.
 * pre: none
 * post: prints the matrix
 * @param matrix the resulting computed matrix
 * @param rows the number of rows
 * @param cols the number of columns
 */
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("| ");
        for (int j = 0; j < cols; j++)
        {
            printf("%12.2f", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * Prints the welcome message upon running.
 * pre: none
 * post: prints welcome message
 */
void printWelcome(void)
{
    printf("\n****************************************\n");
    printf("****************************************\n");
    printf("*****                              *****\n");
    printf("*****       MATRIX CALCULATOR      *****\n");
    printf("*****  BY: CHENYI WANG 05/07/2023  *****\n");
    printf("*****                              *****\n");
    printf("****************************************\n");
    printf("****************************************\n");
}

/**
 * Obtains which matrix function to perform.
 * pre: none
 * post: returns an int of the function to perform
 * @return an int of the function to perform
 */
int setSelection(void)
{
    printf("\n****************************************\n");
    printf("****************************************\n");
    printf("**                                    **\n");
    printf("** MENU OPTIONS:                      **\n");
    printf("** Addition: Enter (1)                **\n");
    printf("** Subtraction: Enter (2)             **\n");
    printf("** Multiplication: Enter (3)          **\n");
    printf("** Scalar Mult/Div: Enter (4)         **\n");
    printf("** Transpose: Enter (5)               **\n");
    printf("**                                    **\n");
    printf("****************************************\n");
    printf("****************************************\n");
    printf("\nPlease select your option: ");

    int selection;
    scanf("%d", &selection);
    while (selection < 1 || selection > 5)
    {
        printf(" *ERROR* Invalid menu option! Please select valid option: ");
        scanf("%d", &selection);
    }

    return selection;
}

/**
 * Obtains the dimensions of the matrix to compute.
 * pre: none
 * post: returns an int of the dimension
 * @param dim 0 to obtain row, 1 to obtain column
 * @return an int of the dimension
 */
int setDim(int dim)
{
    int result;
    if (dim == 0)
    {
        printf("\nEnter the number of rows (1 - 10): ");
    }
    else
    {
        printf("Enter the number of columns (1 - 10): ");
    }
    scanf("%d", &result);
    while (result < 1 || result > 10)
    {
        printf(" *ERROR*  Invalid Dimension, please try again: ");
        scanf("%d", &result);
    }
    return result;
}

/**
 * Sets values within the matrix to be computed.
 * pre: none
 * post: mutates the matrix array to contain the matrix to be computed
 * @param matrix the array container of the matrix
 * @param rows the number of rows in the matrix
 * @param cols the number of columns in the matrix
 */
void setMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the value at row %d, column %d: ", (i + 1), (j + 1));
            scanf("%lf", &matrix[i][j]);
        }
    }
}

/**
 * The add operation of matrices.
 * pre: none
 * post: creates a new matrix array combining the values
 * of the original two matrices
 * @param left the left side matrix
 * @param right the right side matrix
 * @param rows the number of rows of the two matrices
 * @param cols the number of columns of the two matrices
 */
void add(double left[][MAX_SIZE], double right[][MAX_SIZE], int rows, int cols)
{
    double result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = left[i][j] + right[i][j];
        }
    }
    printMatrix(result, rows, cols);
}

/**
 * The subtract operation of matrices.
 * pre: none
 * post: creates a new matrix array with the difference
 * of the original two matrices
 * @param left the left side matrix
 * @param right the right side matrix
 * @param rows the number of rows of the two matrices
 * @param cols the number of columns of the two matrices
 */
void subtract(double left[][MAX_SIZE], double right[][MAX_SIZE], int rows, int cols)
{
    double result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = left[i][j] - right[i][j];
        }
    }
    printMatrix(result, rows, cols);
}

/**
 * The matrix multiplication operation of matrices.
 * pre: none
 * post: creates a new matrix array with the two
 * matrices being multiplied together
 * @param left the left side matrix
 * @param right the right side matrix
 * @param rows the number of rows of the left matrix
 * @param cols the number of columns of the right matrix
 */
void multiply(double left[][MAX_SIZE], double right[][MAX_SIZE], int rows, int cols)
{
    double result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < rows; k++)
            {
                result[i][j] += left[i][k] * right[k][j];
            }
        }
    }
    printMatrix(result, rows, cols);
}

/**
 * The scalar operation of matrices.
 * pre: none
 * post: creates a new matrix array with the scalar applied
 * @param matrix the matrix to be computed
 * @param rows the number of rows of the matrix
 * @param cols the number of columns of the matrix
 * @param scalar the scaling multiple to multiple the matrix
 */
void scalar(double matrix[][MAX_SIZE], int rows, int cols, double scalar)
{
    double result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    printMatrix(result, rows, cols);
}

/**
 * The transpose operation of matrices.
 * pre: none
 * post: creates a new matrix array with the transpose applied
 * @param matrix the matrix to be computed
 * @param rows the number of rows of the matrix
 * @param cols the number of columns of the matrix
 */
void transpose(double matrix[][MAX_SIZE], int rows, int cols)
{
    double result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    printMatrix(result, cols, rows);
}