### 解题思路
在笛卡尔坐标系中，点(x,y)顺时针旋转90°后坐标点为(y,-x)。点(x,y)可以通过对角线翻转(-y,-x)，再水平翻转(y,-x)即可

### 代码

```c
#define SWAP(a,b) do{a^=b;b^=a;a^=b;}while(0)

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    // 对角线翻转
    for (i=0; i < *matrixColSize; i++){
        for (j=i+1; j < *matrixColSize; j++)
            SWAP(matrix[i][j], matrix[j][i]);
    }
    // 水平线翻转
    for (i=0; i < *matrixColSize; i++){
        for (j=0; j < *matrixColSize / 2; j++)
            SWAP(matrix[i][j], matrix[i][*matrixColSize - 1 - j]);
    }
}


```