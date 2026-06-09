![image.png](https://pic.leetcode-cn.com/e4ff3f22979d83a7cade848240c525445cdbfaf0328c13bc23f202b904fc3e28-image.png)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret;
    int left,right,mid;
    ret=malloc(sizeof(int)*2);
    ret[0]=-1;
    ret[1]=-1;
    *returnSize=2;
    if(numsSize==0)
        return ret;
    /* 寻找target左边界 */
    left=0;
    right=numsSize-1;
    while(left<right){
        mid=(right+left)/2;
        if(nums[mid]==target)
        right=mid;
        else if(nums[mid]>target)
        right=mid-1;
        else if(nums[mid]<target)
        left=mid+1;
    }
    if(nums[left]==target)
    ret[0]=left;
    /* 寻找target右边界 */
    left=0;
    right=numsSize-1;
    while(left<right){
        mid=(left+right)/2;
        if(left==mid)
        break;
        if(nums[mid]==target)
        left=mid;
        else if(nums[mid]>target)
        right=mid-1;
        else if(nums[mid]<target)
        left=mid+1;
    }
    /* left取值范围：[0，right-1]，需额外判断nums[left+1]*/
    if(left<numsSize-1 && nums[left+1]==target)
    ret[1]=left+1;
    else if(nums[left]==target)
    ret[1]=left;
    return ret;
}