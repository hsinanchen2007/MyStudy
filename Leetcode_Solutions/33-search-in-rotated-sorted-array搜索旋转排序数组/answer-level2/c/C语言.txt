```
/* 二分查找*/
int dsearch(int *nums, int start, int end, int target)
{
    if (end - start == 1) return -1;
    int i = (start + end)/2;
    if (target == nums[i]) return i;
    if (nums[i] > target) return(dsearch(nums, start, i, target));
    return(dsearch(nums, i, end, target));
}

/*切数组，分成有序无序，有序并且把目标包含了就进行二分查找，否则就继续切*/
int cut(int *nums, int start, int end, int target)
{
    int middle;
    middle = (end - start)/2 + start;
    if (middle ==  start) return -1;
    if (nums[middle] == target) return middle;
    if (nums[middle] < nums[end]) {
        if (nums[middle] < target && nums[end] > target) return dsearch(nums, middle, end,target);
        else return(cut(nums , start, middle, target));
    } else {
        if (nums[middle] > target && nums[0] < target) return dsearch(nums, start, middle,target);
        else  return(cut(nums, middle, end, target));
    }
}

int search(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return -1;
    }
    if (numsSize == 1 && nums[0] != target) {
        return -1;
    }
    if (nums[0] == target) return 0;
    if (nums[numsSize - 1] == target) return numsSize - 1;
    return cut(nums, 0, numsSize - 1, target);
}
```
