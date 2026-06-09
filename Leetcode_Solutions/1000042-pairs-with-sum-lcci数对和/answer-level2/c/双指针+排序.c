### 解题思路
此处撰写解题思路
1、对nums进行qsort从小到大排序；
2、双指针遍历

![image.png](https://pic.leetcode-cn.com/45cb52b929e84672a40cac5d9716d0c12efd32fc3029886c7b5fe779b7316c0d-image.png)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), Cmp);
    int start = 0;
    int end = numsSize - 1;
    int cnt = 0;
    int **res = (int **)malloc(sizeof(int) * numsSize);
    assert(res != NULL);
    memset(res, 0, (sizeof(int) * numsSize));
    while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum < target) {
            start++;
        } else if (sum > target) {
            end--;
        } else {
            res[cnt] = (int *)malloc(sizeof(int) * 2);
            res[cnt][0] = nums[start];
            res[cnt][1] = nums[end];
            cnt++;
            start++;
            end--;
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = cnt;
    return res;
}
```