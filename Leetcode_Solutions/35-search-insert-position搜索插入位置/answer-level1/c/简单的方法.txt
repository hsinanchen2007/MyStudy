### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target)
{
    int i;
    int index=0;
    if(numsSize<0||target<nums[0])
    return 0;
    if(target>nums[numsSize-1])
    return numsSize;
    for(i=0;i<numsSize;i++)
    {
        if(target==nums[i])
        {
            return i;
        }
        else if(target>nums[i])
        {
            index++;
        }

    
        
    }
    return index;

}
```