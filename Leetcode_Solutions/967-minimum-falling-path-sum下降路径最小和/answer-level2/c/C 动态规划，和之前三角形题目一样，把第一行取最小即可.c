#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int minFallingPathSum(int** A, int ASize, int* AColSize)
{
    int rel = 0x7fffffff;

    if (ASize == 1) {      
        return A[0][0];
    }    

    for (int i = ASize - 2; i >= 0; i--) {
        for (int j = 0; j < AColSize[0]; j++) {
            if (j == 0) {
                A[i][j] += MIN(A[i + 1][j], A[i + 1][j + 1]);
            } else if (j == AColSize[0] - 1) {
                A[i][j] += MIN(A[i + 1][j - 1], A[i + 1][j]);
            } else {
                int temp = MIN(A[i + 1][j - 1], A[i + 1][j]);
                A[i][j] += MIN(temp, A[i + 1][j + 1]);
            }           
        }
    }

    for (int i = 0; i < AColSize[0]; i++) {
        rel = MIN(rel, A[0][i]);
    }

    return rel;
}