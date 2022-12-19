```
//寻找两个有序数组中，第k小元素的元素
int findLeastKItem(int* nums1, int startIdx1, int nums1Size, int* nums2, int startIdx2, int nums2Size, int k) {
    if(startIdx1 >= nums1Size) {
        return nums2[startIdx2 + k -1];
    }
    if(startIdx2 >= nums2Size) {
        return nums1[startIdx1 + k -1];
    }
    if(k == 1) {
        return nums1[startIdx1] < nums2[startIdx2] ? nums1[startIdx1] : nums2[startIdx2];
    }
    
    //每个数组各分一半, 分别看一下第k/2小的元素
    int mid1Item = startIdx1 + k/2 <= nums1Size ? nums1[startIdx1 + k/2 - 1] : 0x7FFFFFFF;
    int mid2Item = startIdx2 + k/2 <= nums2Size ? nums2[startIdx2 + k/2 - 1] : 0x7FFFFFFF;
    
    if(mid1Item < mid2Item) {
        return findLeastKItem(nums1, startIdx1 + k/2, nums1Size, nums2, startIdx2, nums2Size, k - k/2);
    }else{
        return findLeastKItem(nums1, startIdx1, nums1Size, nums2, startIdx2 + k/2, nums2Size, k - k/2);
    }
}

//有序数组的中位数，即第k小的元素（或者第k、k+1小的元素的平均值）
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //总长度
    int totalSize = nums1Size + nums2Size;
    //总长度奇数个，则寻找第k小的元素
    //总长度偶数个，则寻找第k、k+1小的元素
    int k1 = (totalSize+1) / 2;     //这里的k1、k2为自然位置序号，即下标+1
    int k2 = (totalSize+2) / 2;     //若总长度奇数个，会有k2 == k1，这样方便统一处理
    
    return 1.00 * ( findLeastKItem(nums1, 0, nums1Size, nums2, 0, nums2Size, k1) + findLeastKItem(nums1, 0, nums1Size, nums2, 0, nums2Size, k2) ) / 2.00;
}
```
