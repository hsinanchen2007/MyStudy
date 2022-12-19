```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    printf("%d,%d",*matrixColSize,matrixSize);
    int temp=0,n=*matrixColSize-1;
    for(int j=0;j<*matrixColSize/2;j++){    
        for(int i=j;i<n-j;i++){          //注意这里i的范围，比如第一行那么i只到倒数第二个
            temp=matrix[i][j];
            matrix[i][j]=matrix[n-j][i];
            matrix[n-j][i]=matrix[n-i][n-j];
            matrix[n-i][n-j]=matrix[j][n-i];
            matrix[j][n-i]=temp;    
        }
    }
}
```
