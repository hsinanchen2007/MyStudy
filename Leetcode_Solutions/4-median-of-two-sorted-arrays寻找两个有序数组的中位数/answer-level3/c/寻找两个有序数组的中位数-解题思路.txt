### 解题思路
看到log(m+n) 想到递归处理，然后找中位数就是不断去掉两个数组的最大最小值，增加index，通过index+size保证数组可见范围不断缩减。


### 代码

```c
double avaVal(int *nums, int numsSize,int numsLeftIndex) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize%2 == 0) {
        //偶数
        return (nums[numsSize/2-1+numsLeftIndex]+nums[numsSize/2+numsLeftIndex])/2.0;
    } else {
        //奇数
        return nums[numsSize/2+numsLeftIndex];
    }
    return 0;
}
double findMedian(int* nums1, int nums1Size,int nums1LeftIndex, int* nums2, int nums2Size,int nums2LeftIndex) { 
    //中止条件
    if (nums1Size==1 && nums2Size==1) {
        return (nums1[nums1LeftIndex]+nums2[nums2LeftIndex])/2.0;
    }

    if (nums1Size == 0) {
        return avaVal(nums2,nums2Size,nums2LeftIndex);
    } else if (nums2Size == 0) {
        return avaVal(nums1,nums1Size,nums1LeftIndex);
    } else if (nums1Size > 0&&nums2Size>0) {
        if (nums1[nums1LeftIndex] <= nums2[nums2LeftIndex]) {
            //去掉最大最小
            if (nums1[nums1LeftIndex+nums1Size-1]>nums2[nums2LeftIndex+nums2Size-1])
            {
               return findMedian(nums1, nums1Size-2,nums1LeftIndex+1, nums2,  nums2Size, nums2LeftIndex);
            } else {
               return findMedian(nums1, nums1Size-1,nums1LeftIndex+1, nums2,  nums2Size-1, nums2LeftIndex);
            }
            
        } else {
            //保证是第一个数组是小值
            return findMedian(nums2, nums2Size,nums2LeftIndex,nums1,nums1Size, nums1LeftIndex);
        }
    } else {
        return 0;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    return findMedian(nums1,nums1Size,0,nums2,nums2Size,0);
}


```