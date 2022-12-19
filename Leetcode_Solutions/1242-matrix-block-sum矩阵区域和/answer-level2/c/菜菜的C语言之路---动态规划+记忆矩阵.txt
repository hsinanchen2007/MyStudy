# 1. C语言知识点
#    1.1 创建二维数组
        (1)为指针int**分配m个int*指针的地址空间
                int**memo = (int**)malloc(m*sizeof(int*)))

        (2)为每个int*指针分配n个int整型的地址空间
                for(int i = 0; i<m ;i++){
                        memo[i] = (int*)malloc(n*sizeof(int));
                }

#    1.2 为指针赋值
        题目的意思是，returnSize指针和returnColumnSizes指针均为已分配
        内存地址的指针。

        由于返回的数组行、列长度未知，因此需要用到returnSize和
        returnColumnSizes得到行与列的长度信息。

        所以这里用*returnSize = matSize;
                 *returnColumnSizes = matColSize;
        来得到返回矩阵的行、列信息

# 2. 思路
        (1) 创建一个memo矩阵，memop[i][j]表示从[0,0]到[i,j]的矩形内数值之和
            如，在本题示例中，memo[1][1] = [0,0]到[1,1]内矩形数值之和，
            为1+2+4+5 = 12

        (2) 创建一个结果矩阵res，res[i][j]表示符合要求的所有元素之和。
            显然，该值也是某矩形内所有元素之和，用memo矩阵表示可得。

# 3. 代码
```
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
// 输入m、n, 创建对应的二维矩阵并初始化为零值后输出;
int** createMatrix(int m, int n) {
	int**a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	return a;
}
// 返回两数最大值
int compareMax(int a, int b) {
	return a > b ? a : b;
}
// 返回两数最小值
int compareMin(int a, int b) {
	return a > b ? b : a;
}
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes) {
	int m = matSize, n = *matColSize;
	if (m == 0 || n == 0) {
		return NULL;
	}
	// 确定行、列号
	*returnSize = matSize;
	*returnColumnSizes = matColSize;
	int**memo = createMatrix(m, n);
	// 创建记忆矩阵memo
	for (int i = 0; i < m;i++) {
		for (int j = 0; j < n;j++) {
			memo[i][j] = mat[i][j];
			if (i > 0) {
				memo[i][j] += memo[i - 1][j];
			}
			if (j > 0) {
				memo[i][j] += memo[i][j - 1];
			}
			if (i > 0 && j > 0) {
				memo[i][j] -= memo[i - 1][j - 1];
			}
		}
	}
	// 创建结果矩阵res
	int**res = createMatrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int r1 = compareMax(i - K, 0), r2 = compareMin(i + K, m - 1);
			int c1 = compareMax(j - K, 0), c2 = compareMin(j + K, n - 1);
			res[i][j] = memo[r2][c2];
			if (r1 > 0) {
				res[i][j] -= memo[r1 - 1][c2];
			}
			if (c1 > 0) {
				res[i][j] -= memo[r2][c1 - 1];
			}
			if (r1 > 0 && c1 > 0) {
				res[i][j] += memo[r1 - 1][c1 - 1];
			}
		}
	}
	return res;
}
```

