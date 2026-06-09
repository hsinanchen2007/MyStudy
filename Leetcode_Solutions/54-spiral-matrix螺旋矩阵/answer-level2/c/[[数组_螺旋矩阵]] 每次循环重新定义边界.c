

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){    
        *returnSize=0;
        return matrix;
    }
    *returnSize = *matrixColSize * matrixSize;
    int *a = (int*)malloc((*matrixColSize * matrixSize)*(sizeof(int)));
    int index=0;
    int i;
    int x1=0,y1=0,x2=*matrixColSize-1,y2=matrixSize-1;
    while(x1<=x2 && y1<=y2){
    for (i=x1;i<=x2;i++) { 
		a[index++] = matrix[y1][i];
	}
    for(i=y1+1;i<=y2;i++){
   		a[index++] = matrix[i][x2];
    }
//只要x或者y有一个方向边界重合，那么剩下的必然是一行或者一列
//上面两个for循环就可以满足
    if(x1<x2 && y1<y2){
        for(i=x2-1;i>x1;i--){
            a[index++] = matrix[y2][i];
        }
        for(i=y2;i>y1;i--){
            a[index++] = matrix[i][x1];
        }
    }
	x1++;
	x2--;
	y1++;
	y2--;
    }
    return a;
}
```