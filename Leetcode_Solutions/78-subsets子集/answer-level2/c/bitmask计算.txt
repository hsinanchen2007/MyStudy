### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int t = (int)pow(2, numsSize);
    *returnSize = t;

    int **res = calloc(t, sizeof(int*));
    *returnColumnSizes = calloc(t, sizeof(int));

    for (int i = 0; i < t; i++) {
        res[i] = calloc(numsSize, sizeof(int));
        int shift = 0;
        int index = 0;
        while (i >> shift) {
            if ((i >> shift) & 0x1) {
                res[i][index++] = nums[shift];
            }
            shift++;
        }
        (*returnColumnSizes)[i] = index;
    }

    return res;
}
```