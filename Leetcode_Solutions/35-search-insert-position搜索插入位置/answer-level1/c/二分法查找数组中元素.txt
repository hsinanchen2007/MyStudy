### 解题思路


### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int mid,high,low;
    high=numsSize-1;
    low=0;
     mid=(high+low)/2;
     if(nums[high]<target)
        return high+1;
    if(target<=nums[low])
        return 0;
    while(mid!=low)
    {
       
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
        {
            high=mid;
            mid=(high+low)/2;
        }
        else
        {
            low=mid;
            mid=(high+low)/2;
        }
    }

        return high;

}
```