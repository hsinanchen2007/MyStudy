### 解题思路
感觉有点假
![TIM图片20200407104954.png](https://pic.leetcode-cn.com/b427598d5b54e16108e7217b29d9d668c9fc57968ab105328d7a8e595a6f6509-TIM%E5%9B%BE%E7%89%8720200407104954.png)

### 代码

```c
//方法一：  先转置矩阵，然后换列
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    //matrixSize -> 行的大小    *matrixColSize  ->列的大小
    //先转置
    int t = 0;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<i; j++){
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
    //再换列(轴对称变换)
    for(int j=0; j<(*matrixColSize)/2; j++){
        for(int i=0; i<matrixSize; i++){
            t = matrix[i][j];
            matrix[i][j] = matrix[i][*matrixColSize-1-j];
            matrix[i][*matrixColSize-1-j] = t;
        }
    }
}


