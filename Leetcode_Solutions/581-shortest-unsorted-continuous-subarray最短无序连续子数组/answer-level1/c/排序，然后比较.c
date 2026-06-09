### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a7695da17d320c719deeee7b47d18e96c34eb16007709c3374b50e77a269cbda-image.png)
不能太依赖leetcode的测试用例，写完了记得自己构造测试用例。

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int findUnsortedSubarray(int* nums, int numsSize){
    int *tmp = calloc(numsSize, sizeof(int));
    memcpy(tmp, nums, sizeof(int) * numsSize);

    qsort(nums, numsSize, sizeof(int), cmp);
    int start, end, i;
    start = end = 0;
    for (i = 0; i < numsSize && tmp[i] == nums[i]; i++) {
        ;
    }
    start = i;
    for (i = numsSize - 1; i >= 0 && tmp[i] == nums[i]; i--) {
        ;
    }
    end = i;

    //printf("end = %d, start = %d\n", end, start);

    if (end > start) {
        return end - start + 1;
    }
    return 0;
}
```