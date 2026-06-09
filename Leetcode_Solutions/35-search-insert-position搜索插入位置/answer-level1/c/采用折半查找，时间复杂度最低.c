### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int mid,low=0,high=numsSize-1;
    while(low<=high){
        mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]>=target){
            return i;
        }
    }
    return numsSize;
}
```