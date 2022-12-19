```
int findMin(int* nums, int numsSize){
    int left = 0,right = numsSize - 1;
    if (nums[left] <= nums[right]){
        return nums[left];
    }
    int mid = (right + left)/2;
    while(mid != left){
        if(nums[mid] < nums[mid - 1]) return nums[mid];
        else if (nums[mid]>nums[left]) left = mid;
        else right = mid;
        mid = (right + left)/2;
    } 
    return nums[right];
}
```
提交的代码中暴力搜索的比二分查找的快。。。