### 解题思路
找到第一个大于等于目标数的位置并返回。
如果没有返回 最后一位+1

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;++i)
        if(nums[i]>=target)
            return i;
    return numsSize;
}
```