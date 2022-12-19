### 解题思路
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]



### 代码

```c

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp, temp2;
    
    for (i = 0; i <= (matrixSize - 1)/2; i++) {
        for (j = i; j < matrixSize - 1 - i; j++) {
            temp = matrix[j][matrixSize-1-i];
            matrix[j][matrixSize-1-i] = matrix[i][j];
            temp2 = matrix[matrixSize-1-i][matrixSize-1-j];
            matrix[matrixSize-1-i][matrixSize-1-j] = temp;
            matrix[i][j] = matrix[matrixSize-1-j][i];
            matrix[matrixSize-1-j][i] = temp2;
        }
    }
}
```