
/********/
* 1  2  3
* 4  5  6
* 7  8  9
*    |
*    V
* 9  6  3
* 8  5  2
* 7  4  1
*    |
*    V
* 7  4  1
* 8  5  2
* 9  6  3
**********/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i=0,j,m;
    while(i<matrixSize)
    {
        j=0;
        while(j<*matrixColSize-i-1)
        {
            m=matrix[i][j];
            matrix[i][j]=matrix[matrixSize-j-1][matrixSize-i-1];
            matrix[matrixSize-j-1][matrixSize-i-1]=m;
            j++;
        }
        i++;
    }
    i=0;
    j=0;
    while(i<matrixSize/2)
    {
        j=0;
        while(j<*matrixColSize)
        {
            m=matrix[i][j];
            matrix[i][j]=matrix[matrixSize-i-1][j];
            matrix[matrixSize-i-1][j]=m;
            j++;
        }
        i++;
    }
}