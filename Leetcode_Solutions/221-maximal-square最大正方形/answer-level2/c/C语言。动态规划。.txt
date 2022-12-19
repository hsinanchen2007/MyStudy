```
/**
 * dp表示最大正方形边长，dp[i][j] = MIN(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int i, j, max;
	int** dp = (int**)malloc(sizeof(int*) * matrixSize);
	for(i = 0; i < matrixSize; i++){
	    dp[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
	}
	
    max = 0;
	for(i = 0; i < matrixSize; i++){
	    for(j = 0; j < matrixColSize[0]; j++){
		    if(matrix[i][j] == '1'){
			    dp[i][j] = MIN(i > 0 && j > 0 ? dp[i-1][j-1] : 0, MIN(j > 0 ? dp[i][j-1] : 0, i > 0 ? dp[i-1][j] : 0)) + 1;
                max = MAX(max, dp[i][j]);
			}else{
			   dp[i][j] = 0;
			}
		}
	}
	
	return max * max;
}
```
