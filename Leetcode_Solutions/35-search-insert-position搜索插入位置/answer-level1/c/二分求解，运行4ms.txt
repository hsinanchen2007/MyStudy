### 解题思路
由于时有序数组的查找，符合二分查找的条件。我并没有纯粹二分查找，二分的目的是为了降低复杂度。我等到问题规模降低到足够小时，再使用遍历的方法，简洁而不简单。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int l=0;
    int r=numsSize-1;
    int m = (l+r)/2;
    if(target < nums[l]) return 0;
    if(target > nums[r]) return numsSize;
    while(r-l>2)
    {
        if(nums[m] > target){
            r = m;
            m = (l+r)/2; 
        }
        else if(nums[m] < target){
            l = m;
            m = (l+r)/2;
        }
        else{
            return m;
        }
    }
    for(int i=l;i<=r;i++){
        if(nums[i] >= target){
            return i;
        }        
    }
    return 0;
}
```