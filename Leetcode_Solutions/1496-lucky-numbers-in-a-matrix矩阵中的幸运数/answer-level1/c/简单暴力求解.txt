### 解题思路
记录所有行最小值，记录所有列最大值，然后其中行最小值==列最大值的值即为结果

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int i,j,*p,*q,max,*a,x=0;
    max=matrixSize>*matrixColSize?*matrixColSize:matrixSize;
    p=(int *)malloc(sizeof(int)*matrixSize);
    q=(int *)malloc(sizeof(int)*(*matrixColSize));
    a=(int *)malloc(sizeof(int)*max);
    for(i=0;i<matrixSize;i++){//0,0 0,1 0,2
        *(p+i)=matrix[i][0];
        for(j=1;j<*matrixColSize;j++){
            
            if(*(p+i)>matrix[i][j]){
                *(p+i)=matrix[i][j];
            }
        }
    }

    for(i=0;i<*matrixColSize;i++){
        *(q+i)=matrix[0][i];//0,0 1,0 2,0 0,1 1,1
        for(j=1;j<matrixSize;j++){
            if(*(q+i)<matrix[j][i]){
                *(q+i)=matrix[j][i];
            }
        }
    }

    for(i=0;i<matrixSize;i++){
        for(j=0;j<*matrixColSize;j++){
            if(*(p+i)==*(q+j)){
                *(a+x)=*(p+i);
                x++;
            }
        }
    }
    *returnSize=x;
    return a;

}
// 1 3 15
// 15 16 17 12
```