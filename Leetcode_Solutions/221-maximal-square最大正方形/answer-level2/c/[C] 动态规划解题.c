### 解题思路
此处撰写解题思路

### 代码

```c
int arr_min(int num1, int num2){
    return num1 < num2 ? num1 : num2;
}

int arr_max(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

    int ** arr = (int**)malloc(sizeof(int*) * matrixSize );
    for( int i = 0 ; i < matrixSize ;i++){
        arr[i] = (int*)malloc(sizeof(int) * matrixColSize[0] );
    }
    int i , j ,len = 0;

    for ( i = 0 ; i < matrixSize ; i++){
        for( j = 0 ; j < matrixColSize[0] ; j++){
            if(matrix[i][j] == '1'){
                arr[i][j] = arr_min(arr_min(i > 0  ? arr[i-1][j] : 0 ,  j > 0 ? arr[i][j-1] : 0), i > 0 && j > 0 ? arr[i-1][j-1] : 0) + 1;
                len = arr_max(len, arr[i][j]);
            }else{
                arr[i][j] = 0;
            }
        }
    } 
    return len * len;                                                                 
}
```