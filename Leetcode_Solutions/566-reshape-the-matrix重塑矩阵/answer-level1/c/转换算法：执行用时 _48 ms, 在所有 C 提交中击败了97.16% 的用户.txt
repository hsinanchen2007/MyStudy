解题思路
1.本题解题最核心的思想是：转换后的数组个数与原始数组个数是否相同。二维数组转换为一维数组，再通过一维数组转换为二维数组。
2.基于1，对原始数组的行列相乘的值与新数组行列相乘的值进行比较，如果不相等，返回原始数组。
3.如果行列乘积值相等，说明可以进行转换。
4.原始的二维数组转换为一维数组。
5.基于新生成数组的行和列，进行一维数组转为为二维数组。
6.返回新数组。

具体代码流程：
    int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
        int i, j, l, m, k;
        int **returnnums;
        int *p, *q;

        q = (int *) malloc(sizeof(int) * r);
        if (numsSize * *numsColSize != r * c || r <= 0 || c <= 0) {
            for (i = 0; i < r; i++) {
                q[i] = * numsColSize;
            }
            *returnColumnSizes = q;
            *returnSize = numsSize;
            *returnColumnSizes = q;
            return nums;
        }
        p = (int *) malloc(sizeof(int) * (r * c));

        returnnums = (int **)malloc(sizeof(int *) * r);
        for (i = 0; i < r; i++) {
            returnnums[i] = (int *)malloc(sizeof(int ) * c);
        }
        l = 0;
        m = 0;
        k = 0;
        for (i = 0; i < numsSize; i++) {
            for (j = 0; j < *numsColSize; j++) {
                p[k] = nums[i][j];
                k++;
            }
        }
        k = 0;
        for (l = 0, k = 0; l < r; l++) {
            for (m = 0; m < c; m++) {
                returnnums[l][m] = p[k];
                k++;
            }
        }

        *returnSize = r;
        for (i = 0; i < r; i++) {
            q[i] = c;
        }
        *returnColumnSizes = q;

        free(p);
        p = NULL;
        for (i = 0; i < r; i++) {
            free(q[i]);
            q[i] = NULL;
        }

        return returnnums;
    }