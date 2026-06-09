### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize-1, mid = 0, i = 0;  
    while(left <= right)
    {
        mid = (left + right)/2;
        if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else
            break;
    }
    if(nums[mid] < target)
        return mid + 1;
    else if(nums[mid] > target)
        return mid;
    else
        return mid;

}


```