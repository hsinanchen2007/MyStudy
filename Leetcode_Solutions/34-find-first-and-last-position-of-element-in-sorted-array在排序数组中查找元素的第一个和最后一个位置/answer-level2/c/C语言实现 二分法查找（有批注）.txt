![微信图片_20200215112335.jpg](https://pic.leetcode-cn.com/be6b5b1d659aa0fd6d690d4111a6efa33831bec079c0d5b621da43b1b05e8c74-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200215112335.jpg)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
*returnSize=2;
int *res = (int *)malloc(sizeof(int)*2);
//寻找区间左端
int left = 0;
int right = numsSize;//意味着左闭右开
while(left < right)//注意无等号
{
    int mid = (left+right)/2;
    if(target < nums[mid])
    right = mid;//右端是开，为了去掉mid
    else if(target > nums[mid])
    left = mid+1;//左端是闭,为了去掉mid
    else if(target==nums[mid])
    right = mid;//缩小右端，使范围不断向左收缩
}
if(right==numsSize)//或者left==numsSize,因为循环终止条件使left==right
res[0]=-1;//所有的数都比target小
else if(nums[left]==target)
res[0]=left;
else
res[0]=-1;//由于while无等号，循环终止区间为[left,left)
//寻找区间右端
left=0;
right=numsSize;
while(left<right)
{
    int mid=(left+right)/2;
    if(target<nums[mid])
    right=mid;
    else if(target>nums[mid])
    left=mid+1;
    else if(target==nums[mid])
    left=mid+1;//与左端不同，还是由区间是左闭右开引起的
}
if(left==0)
res[1]=-1;//target比所有数都小
else if(nums[left-1]==target)
res[1]=left-1;//需要减1，因为target==nums[mid]时，mid=left-1;
else
res[1]=-1;
return res;
}