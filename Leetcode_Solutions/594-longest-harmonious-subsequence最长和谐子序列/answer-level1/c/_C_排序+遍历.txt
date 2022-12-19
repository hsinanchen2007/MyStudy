### 解题思路
先从小到大排序，再做差值，每次做差值时，把满足要求的最小值的startIdx记下来，做为下次查找区间的最小索引。
![123.PNG](https://pic.leetcode-cn.com/7e9bb26f39bffb8cdec590cc997d622f3930aded82b4911a1ed211f63aad6600-123.PNG)


### 代码

```c
int Cmp(const void *ele1, const void *ele2)
{
    int *p1 = (int *)ele1;
    int *p2 = (int *)ele2;
    if (*p1 < *p2) {
        return -1;
    } else if (*p1 > *p2) {
        return 1;
    }
    return 0;
}
int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), Cmp);
    int max, i, j, startIdx;
    i = max = startIdx = 0;
    while (i < numsSize) {
        for (j = startIdx; j <= i; j++) {
            int diff = nums[i] - nums[j];
            if (diff == 1) {
                startIdx = j;
                break;
            }
        }
        if (i - j + 1 >= max) {
            max = i - j + 1;
        }
        i++;
    }
    return max;
}
```