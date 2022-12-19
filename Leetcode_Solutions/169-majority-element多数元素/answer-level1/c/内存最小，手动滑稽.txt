```C
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize/2];
}
```

![image.png](https://pic.leetcode-cn.com/77c6a94012baad0684bebf2ee2383d857bcff9dc5cf2bf59872e4b95b6141243-image.png)
