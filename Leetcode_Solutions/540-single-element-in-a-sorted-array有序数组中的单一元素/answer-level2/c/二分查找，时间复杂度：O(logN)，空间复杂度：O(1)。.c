# 算法思想：二分查找。原来的数组中，出现两次的数字都是成对出现，因此在遇到只出现一次的数字时，之前的下标都是[0,1],[2,3],[4,5]...,都是偶数开头，并且nums[i] = nums[i+1]。利用二分查找，使得中位数也是偶数的情况下，通过判断nums[i] = nums[i+1]是否成立，来判断唯一数出现在当前中位数的左边还是右边。
int singleNonDuplicate(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    while(left < right){
        int mid =  left + (right - left) / 2;
        if(mid % 2 == 1){
            mid --;
        }
        if(nums[mid] == nums[mid + 1]){
            left = mid + 2;
        }else{
            right = mid;
        }
    }
    return nums[left];
}
```
