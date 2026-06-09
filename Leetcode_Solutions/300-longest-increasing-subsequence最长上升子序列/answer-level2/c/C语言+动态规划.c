### 解题思路
动态规划典型问题

### 代码

```c
int lengthOfLIS(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int *opt = (int *)malloc(sizeof(int) * numsSize);
    int i, j, max;
    opt[0] = 1;
    max = opt[0];
    for (i = 1; i < numsSize; i++) {
        opt[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                opt[i] = (opt[i] < (opt[j] + 1)) ? (opt[j] + 1) : opt[i];
            }
        }
        max = (opt[i] > max) ? opt[i] : max;
    }
    free(opt);
    return max;
}

```