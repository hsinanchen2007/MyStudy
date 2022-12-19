### 解题思路
此处撰写解题思路

### 代码

```c
int search(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1;int output=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            output=mid;
            return output;
        }
        if(nums[low]<=nums[mid]){
            if(target>=nums[low]&&target<nums[mid])
                high=mid-1;
            else
                low =mid+1;
        }
        else{
            if(target>nums[mid]&&target<=nums[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}
```