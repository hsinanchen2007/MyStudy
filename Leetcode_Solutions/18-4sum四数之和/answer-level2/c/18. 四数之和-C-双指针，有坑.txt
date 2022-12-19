### 解题思路
在三数和那道题外面再嵌套一层循环。
需要注意的是这道题的去重条件

固定 Now， then， low， high，
固定now， then，动low，high  
        移动then
移动now

对于now和then都要做去重。
```
while (now > 0 && (now + 3) < numsSize && nums[now] == nums[now - 1]) {
    now++;
}
```

then去重的时候要考虑到：
比如0,0,0,0这种组合，then如果上一个就是now，但是它们又相等，这种情况不能算是重复的
```
while ((then + 2) < numsSize  && then > (now + 1) && nums[then] == nums[then - 1]) {
    then++;
}
```

### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), Compare);
    int **res = (int **)malloc(sizeof(int *) * numsSize * 6);
    *returnSize = 0;

    int now = 0;
    int then;
    int low;
    int high;

    while ((now + 3) < numsSize) {
        while (now > 0 && (now + 3) < numsSize && nums[now] == nums[now - 1]) {
            now++;
        }

        if (now + 3 >= numsSize) {
            break;
        }

        int then = now + 1;
        while ((then + 2) < numsSize) {
            while ((then + 2) < numsSize  && then > (now + 1) && nums[then] == nums[then - 1]) {
                    then++;
            }
            if (then + 2 >= numsSize) {
                break;
            }
            low = then + 1;
            high = numsSize - 1;
            int t = target - nums[now] - nums[then];

            while (low < high && low < numsSize && high > then) {
                if (nums[low] + nums[high] == t) {
                    res[(*returnSize)] = (int *)malloc(sizeof(int) * 4);
                    res[(*returnSize)][0] = nums[now];
                    res[(*returnSize)][1] = nums[then];
                    res[(*returnSize)][2] = nums[low];
                    res[(*returnSize)][3] = nums[high];
                    (*returnSize)++;

                    int temp_low = nums[low];
                    int temp_high = nums[high];

                    while (low < numsSize && nums[low] == temp_low) {
                        low++;
                    }
                    while (high > then && nums[high] == temp_high) {
                        high--;
                    }
                    if (high <= low) {
                        break;
                    }
                    continue;
                }

                if (nums[low] + nums[high] > t) {
                    high--;
                    continue;
                }

                if (nums[low] + nums[high] < t) {
                    low++;
                    continue;
                }
            }
            then++;
            low = then + 1;
            high = numsSize - 1;
        }
        now++;
        then = now + 1;
        low = then + 1;
        high = numsSize - 1;
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * 6);
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 4;
    }

    return res;

}

```