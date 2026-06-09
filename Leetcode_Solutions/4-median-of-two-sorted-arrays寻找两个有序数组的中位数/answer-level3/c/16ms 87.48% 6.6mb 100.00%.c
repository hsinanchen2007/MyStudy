### 解题思路
这题用归并看来成绩也不是很差嘛，是因为大家用归并的更多吗[手动滑稽]

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *nums3=(int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    int k1=0,k2=0,t=0;
    while(k1<nums1Size&&k2<nums2Size){
        if(nums1[k1]<nums2[k2]){
            nums3[t++]=nums1[k1++];
        }else{
            nums3[t++]=nums2[k2++];
        }
    }
    while(k1<nums1Size){
        nums3[t++]=nums1[k1++];
    }
    while(k2<nums2Size){
        nums3[t++]=nums2[k2++];
    }
    return (nums3[t/2]+nums3[(t-1)/2])/2.0;
}
```