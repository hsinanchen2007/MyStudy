**case1: nums[low] <= nums[mid]    e.g.[3,4,5,6,7,1,2]**
**case2: nums[low] > nums[mid]     e.g.[6,7,1,2,3,4,5]**
```
int search(int* nums, int numsSize, int target){
    if(numsSize == 0)
        return -1;
    int low = 0, high = numsSize - 1, mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(nums[mid] == target)
            return mid;
        /*前半部分有序*/
        if(nums[low] <= nums[mid]){
            /*target在前半部分*/
            if(target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        /*后半部分有序*/
        else{
            /*target在后半部分*/
            if(target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
```