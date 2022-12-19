### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    int i, j, k;
    int m = (target % 2) ? (target + 1) / 2 : target / 2;
    int sum, num;
    int** ret = (int **)malloc(sizeof(int *) * m);
    int *columnSizes = (int *)malloc(sizeof(int) * m);
    int size = 0;
    for (i = 1; i < m; i++) {
        sum = i;
        for (j = i + 1; j <= m; j++) {
            sum += j;
            if (sum > target) {
                break;
            } else if (sum == target) {
               num = j - i + 1;
               ret[size] = (int *)malloc(sizeof(int) * num);
               columnSizes[size] = num;
               for (k = 0; k < num; k++) {
                   ret[size][k] = i + k;
               }
               size++;
               break; 
            }
        }
    }
    *returnSize = size;
    *returnColumnSizes = columnSizes;

    return ret;
}
```