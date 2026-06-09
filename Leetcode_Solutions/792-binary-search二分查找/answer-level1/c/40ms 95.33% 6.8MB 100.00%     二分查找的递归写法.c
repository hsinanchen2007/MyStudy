
```
int binarysearch(int* nums, int left, int right, int target){
    int index, mid=(left+right)/2;
    if(nums[left]>target || nums[right]<target) return -1;
    else if(nums[mid]==target) return mid;
    else if(nums[mid]<target) index = binarysearch(nums, mid+1, right, target);
    else index = binarysearch(nums, left, mid-1, target);
    return index;
}
int search(int* nums, int numsSize, int target){
    if(!numsSize) return -1;
    return binarysearch(nums, 0, numsSize-1, target);
}
```
