### 解题思路
执行结果：通过显示详情 执行用时 :48 ms, 在所有 c 提交中击败了97.10%的用户
内存消耗 :12.8 MB, 在所有 c 提交中击败了76.19%的用户
（1）找出特殊情况，返回原有矩阵，注意空间开辟
（2）按r/c的关系进行循环赋值即可，关键在于二级指针的应用及相应空间开辟
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int **pArr;
    int i;
    int j;
    int m, n;
    int totalNum;
    // check the abnormal
    totalNum = numsSize * (*numsColSize);
    if (totalNum / r != c) {
        *returnSize = numsSize;
        *returnColumnSizes = (int *)malloc(sizeof(int) * (numsSize));
        pArr = (int **)malloc(sizeof(int *) * numsSize);
        for (i = 0; i < numsSize; i++) {
            *(*returnColumnSizes + i) = *numsColSize;
            pArr[i] = (int *)malloc(sizeof(int) * (*numsColSize));
            memcpy(pArr[i], nums[i], sizeof(int) * (*numsColSize));
        }
        return pArr; // return the original array
    }

    pArr = (int **)malloc(sizeof(int *) * r);
    *returnSize = r;
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    m = 0;
    n = 0;
    for (i= 0; i < r; i++) {
        pArr[i] = (int *)malloc(sizeof(int) * c);
        for (j = 0; j < c; j++) {
            pArr[i][j] = nums[m][n++];
            if (n == *numsColSize) {
                n = 0;
                m++;
            }
        }
        *(*returnColumnSizes + i) = c;
    }

    return pArr;

}
```