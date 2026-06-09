### 解题思路
两个有序数组合并为一个有序数组，然后取中位数

### 代码

```c
int* getMergeArray(int * nums1,int nums1Size,int * nums2,int nums2Size,int * retArray,int retArraySize)
{
    if(retArraySize==0){
        return retArray;
    }
    if(nums1Size==0&&nums2Size==0){
        return retArray;
    }
    if(nums1Size==0){
        retArray[retArraySize-1] = nums2[nums2Size-1];
        nums2Size--;
        retArraySize--;
        return getMergeArray(nums1,nums1Size,nums2,nums2Size,retArray,retArraySize); 
    }
    if(nums2Size==0){
        retArray[retArraySize-1] = nums1[nums1Size-1];
        nums1Size--;
        retArraySize--;
        return getMergeArray(nums1,nums1Size,nums2,nums2Size,retArray,retArraySize); 
    }
    if(nums1Size>0&&nums2Size>0&&nums1[nums1Size-1]>=nums2[nums2Size-1]){
        retArray[retArraySize-1] = nums1[nums1Size-1];
        nums1Size--;
        retArraySize--;
        return getMergeArray(nums1,nums1Size,nums2,nums2Size,retArray,retArraySize); 
    }
    if(nums1Size>0&&nums2Size>0&&nums1[nums1Size-1]<nums2[nums2Size-1]){
        retArray[retArraySize-1] = nums2[nums2Size-1];
        nums2Size--;
        retArraySize--;
        return getMergeArray(nums1,nums1Size,nums2,nums2Size,retArray,retArraySize); 
    }
    return getMergeArray(nums1,nums1Size,nums2,nums2Size,retArray,retArraySize); 
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int recSize = (nums1Size+nums2Size)/2+1;
    int * recArray = (int *)malloc(sizeof(int)*recSize);
    recArray = getMergeArray(nums1,nums1Size,nums2,nums2Size,recArray,recSize);
    if((nums1Size+nums2Size)%2 == 0){
        double d = ((recArray[0]+recArray[1])*1.0)/2;
        return d;
    }else{
        return recArray[0];
    }
}
```