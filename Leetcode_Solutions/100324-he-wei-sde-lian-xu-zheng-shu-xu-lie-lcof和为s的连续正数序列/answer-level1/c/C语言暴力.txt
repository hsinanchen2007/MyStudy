### 解题思路
此处撰写解题思路

### 代码

```c
/* 和为s的连续正数序列 滑动窗口 */

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    int **arr = (int **)malloc(sizeof(int *) * target);
   // memset(arr, 0x0, sizeof(int *) * target);
    int *arrCol = (int *)malloc(sizeof(int) * target);
    memset(arrCol, 0x0, sizeof(int) * target);
    int sum;
    int count = 0;

    for (int i = 1; i<= (target / 2); i++) {
        int j = i;
        sum = 0;
        for ( ; sum < target; j++) {
            sum = sum + j;
        }

        if (sum == target) {
            int r = 0;
            printf("%d\n", j);
            int arrLen = j - i;
            arrCol[count] = arrLen;
            arr[count] = (int *)malloc(sizeof(int) * arrLen);
            memset(arr[count], 0x0, sizeof(int) * arrLen);
            for (int k = i; k < j; k++) {
                arr[count][r] = k;
                printf("%d %d\n", k, arr[count][r]);
                r++;
            }

            count++;
        }
    }

    *returnSize = count;
    *returnColumnSizes = arrCol;
    return arr;
}
```