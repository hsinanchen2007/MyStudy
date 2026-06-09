### 解题思路
一循环来实现冒泡排序的逐个排查，一选择来判断位置

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>=target)
        return i;
    }
    return numsSize;
}
```