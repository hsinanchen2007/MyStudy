### 解题思路
本题考查数组下标关系，以及原位交换的知识，这里给出C语言的写法。

关键点：
1.根据第一个点计算其他三个点的位置
2.原位异或交换

![image.png](https://pic.leetcode-cn.com/c38d6494f4b1a02c0607e218259a3c1eb4d6c664c42a594579d925a1647521c6-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void swap(int *a, int *b) {
    (*a) = (*a) ^ (*b);
    (*b) = (*a) ^ (*b);
    (*a) = (*a) ^ (*b);
}

//【算法思路】数组。
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int row = matrixSize;
    int loop = row / 2;

    for(int lvl = 0; lvl < loop; lvl++) {
        for(int i = lvl; i < row - 1 - lvl; i++) {
            //交换4个点
            int y0, y1, y2, y3;
            int x0, x1, x2, x3;

            y0 = lvl;
            x0 = i;

            y1 = i;
            x1 = row - 1 - lvl;
            swap(&matrix[y0][x0], &matrix[y1][x1]);

            y2 = row - 1 - lvl;
            x2 = row - 1 - i;
            swap(&matrix[y0][x0], &matrix[y2][x2]);

            y3 = row - 1 - i;
            x3 = lvl;
            swap(&matrix[y0][x0], &matrix[y3][x3]);

            //printf("[%d, %d], [%d, %d], [%d, %d], [%d, %d]\n", 
            //        y0, x0, y1, x1, y2, x2, y3, x3);
        }
    }
}
```