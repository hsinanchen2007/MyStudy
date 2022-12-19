### 解题思路
1.当在数组中找到目标值时，使用典型的二分查找。
2.如果目标值不存在于数组中，将目标值按顺序与数组中的元素比较，当目标值小于该元素时，返回此时该元素的索引。否则，继续与下一个元素比较。当目标值大于该数组所有元素时，返回numsSize。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target)
{
    int low=0,i=0;
    int high=numsSize-1;
    int mid=0,guess=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        guess=nums[mid];
        if(guess==target)
            return mid;
        else if(guess>target)
            high=mid-1;
        else
            low=mid+1;
    }
    for(i=0;i<numsSize;i++)
    {
        if(target<nums[i])
            return i;
    }
    return numsSize;
}
```