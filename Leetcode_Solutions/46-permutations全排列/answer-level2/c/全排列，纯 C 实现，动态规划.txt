![2019-10-18_19-56.png](https://pic.leetcode-cn.com/619b64289f132851ae0ada703f53944214bd5f8c59fdcebeb2f6f2047d0aed05-2019-10-18_19-56.png)

```c
int **permuteHelper(int *nums, int numsSize, int *returnSize) {
    // 只有一个元素时直接返回该元素，并且只有一种排列
    if (numsSize == 1) {
        *returnSize = 1;
        int **ret = (int **) malloc(sizeof(int *) * (*returnSize));
        *ret = (int *) malloc(sizeof(int));
        **ret = *nums;
        return ret;
    }

    // 将排除第一个数字的 nums 作为子问题进行求解
    int **child = permuteHelper(nums + 1, numsSize - 1, returnSize);
    // 新组合的个数为子问题的组合个数乘上当前问题数组的长度 n * (n - 1)!
    int newSize = (*returnSize) * numsSize;
    int **ret = (int **) malloc(sizeof(int *) * newSize);
    // 对于子问题的每个组合，都可扩展为 numsSize 个
    // 如 [1 2 3] 有 4 种插入方式 [[^1 2 3], [1^2 3], [1 2^3], [1 2 3^]]
    for (int i = 0; i < *returnSize; i++) {
        // 要插入的位置为 j
        for (int j = 0; j < numsSize; j++) {
            int index = i * numsSize + j;
            ret[index] = (int *) malloc(sizeof(int) * (numsSize));
            // 拷贝 j 之前的元素
            for (int k = 0; k < j; k++) {
                ret[index][k] = child[i][k];
            }
            // 将当前的数字放到第 j 个位置
            ret[index][j] = *nums;
            // 拷贝 j 之后的元素
            for (int k = j + 1; k < numsSize; k++) {
                ret[index][k] = child[i][k - 1];
            }
        }
        free(child[i]);
    }
    free(child);
    // 更新返回的组合数
    *returnSize = newSize;
    return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret = permuteHelper(nums, numsSize, returnSize);
    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    return ret;
}
```