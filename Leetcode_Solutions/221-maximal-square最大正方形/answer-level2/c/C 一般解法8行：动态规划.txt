### 解题思路

![演示文稿1.jpg](https://pic.leetcode-cn.com/15f53dc2688f3c3ab08e71468c2a76bd978675f3ccefa440a5a7a14c30b21f7e-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.jpg)

为了更简洁和可读在原数据上进行修改，有效代码8行

### 代码

```c
#define MIN(a,b,c) ((a)<(b)?( (a)<(c)?(a):(c) ):( (b)<(c)?(b):(c) ))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0) return 0;
    int j,k,ms = matrix[0][0];
    for(j=0;j<matrixSize;j++)
        for(k=0;k<matrixColSize[j];k++){
            if(matrix[j][k]=='1' && j>0 && k>0) matrix[j][k] = MIN(matrix[j-1][k],matrix[j][k-1],matrix[j-1][k-1]) + 1;
            if(matrix[j][k] > ms) ms = matrix[j][k];
        }
    return (ms-'0')*(ms-'0');
}
```