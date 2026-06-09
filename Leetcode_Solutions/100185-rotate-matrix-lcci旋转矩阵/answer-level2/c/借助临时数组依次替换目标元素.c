![解题.PNG](https://pic.leetcode-cn.com/dfa02bb49b3d3e7c9aa1f0df48cb5bf73aba1ef645d05651394c39f386008a4b-%E8%A7%A3%E9%A2%98.PNG)


### 解题思路
- 每圈的元素移动可以看成*matrixColSize - 1个元素替换右列matrixSize - 1个元素，重复4次，即可完成一圈旋转。
- 起始坐标递增，进入下一圈，直到替换完成。
- 使用两个临时数组，用来交替存放要被替换掉的元素，按题目要求，不是最佳解，但是也没想到更好的办法。

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i;
    int j;     // 临时数组游标
    int x = 0; // 起始坐标

    int *tmp1 = (int*)malloc(sizeof(int) * (matrixSize - 1)); // 临时数组，下同
    int *tmp2 = (int*)malloc(sizeof(int) * (matrixSize - 1)); 

    while (matrixSize > 0) { // 因为是正方形矩阵，所以matrixSize == *matrixColSize，任取其一使用
        for (i = x, j = 0; i < matrixSize - 1; i++, j++) {
            tmp1[j] = matrix[i][matrixSize - 1]; // 保存被替换的元素，用于下次替换其他的元素
            matrix[i][matrixSize - 1] = matrix[x][i];
        }

        for (j = 0; i > x; i--, j++) {
            tmp2[j] = matrix[matrixSize - 1][i]; // 保存被替换的元素，用于接下来替换其他的元素
            matrix[matrixSize - 1][i] = tmp1[j]; // 用上次保存的元素替换目标元素
        }

        for (i = matrixSize - 1, j = 0; i > x; i--, j++) {
            tmp1[j] = matrix[i][x]; // 同上
            matrix[i][x] = tmp2[j];
        }

        for (j = 0; i < matrixSize - 1; i++, j++) {
            matrix[x][i] = tmp1[j];
        }

        x++; // 起始坐标递增，进入下一圈，因为是正方形矩阵，所以用一个变量表示就行
        matrixSize--;
    }
    free(tmp1);
    free(tmp2);
}
```