### 解题思路
Wait想念的C版本
### 代码

```c
int finKthVal(int* nums1, int nums1Size,int i, int* nums2, int nums2Size,int j,int k){
    if(i>=nums1Size) return nums2[j+k-1];
    if(j>=nums2Size) return nums1[i+k-1];
    if(k==1){return nums1[i]<nums2[j]?nums1[i]:nums2[j];}
    int midVal1 = (i+k/2-1<nums1Size)?nums1[i+k/2-1]:INT_MAX;
    int midVal2 = (j+k/2-1<nums2Size)?nums2[j+k/2-1]:INT_MAX;
    if(midVal1<midVal2)
        return finKthVal(nums1,nums1Size,i+k/2,nums2,nums2Size,j,k-k/2);
    else
        return finKthVal(nums1,nums1Size,i,nums2,nums2Size,j+k/2,k-k/2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int leftP = (nums1Size+nums2Size+1)/2;
    int rightP = (nums1Size+nums2Size)/2+1;
    return (finKthVal(nums1,nums1Size,0,nums2,nums2Size,0,leftP)+
            finKthVal(nums1,nums1Size,0,nums2,nums2Size,0,rightP))/2.0;
}

```