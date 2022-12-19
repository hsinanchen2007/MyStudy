### 解题思路
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2



### 代码

```c
int searchInsert(int* nums, int numsSize, int target){

    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = l+ (r - l)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    //此题，正好返回left即可， left最后比right小1
    return l;
}
```