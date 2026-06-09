```
int leftSearchRange(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize;
    while(left < right){
        int mid =  left + (right - left) / 2;
        if(nums[mid] >= target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    if(left == numsSize){
        return -1;
    }
    return nums[left] == target? left : -1;
}
int rightSearchRange(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize;
    while(left < right){
        int mid =  left + (right - left) / 2;
        if(nums[mid] <= target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    if(left == 0){
        return -1;
    }
    return nums[left - 1] == target? left -1 : -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int first = leftSearchRange(nums, numsSize, target);
    int last = rightSearchRange(nums, numsSize, target);
    int* returnArray = (int*)malloc(sizeof(int) * 2);
    returnArray[0] = first;
    returnArray[1] = last;
    return returnArray;
}
```
