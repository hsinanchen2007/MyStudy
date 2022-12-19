![2019-11-03_10-15.png](https://pic.leetcode-cn.com/427873653035e97648761c327819d07e404baaa7e05d3992fd25050b2b81c9e4-2019-11-03_10-15.png)


```c
void rotate(int **matrix, int matrixSize, int *matrixColSize) {
  // 用来交换数字的临时变量
  int buffer = 0;

  // 矩阵的半宽
  int half = matrixSize >> 1;
  // i 的轴对称
  int symI;
  // j 的轴对称
  int symJ;

  // 由外向內逐层处理
  for (int i = 0; i < half; i++) {
    symI = matrixSize - i - 1;
    for (int j = i; j < symI; j++) {
      symJ = matrixSize - j - 1;
      // 中心对称的 4 个变量顺时针旋转
      buffer = matrix[i][j];
      matrix[i][j] = matrix[symJ][i];
      matrix[symJ][i] = matrix[symI][symJ];
      matrix[symI][symJ] = matrix[j][symI];
      matrix[j][symI] = buffer;
    }
  }
}
```