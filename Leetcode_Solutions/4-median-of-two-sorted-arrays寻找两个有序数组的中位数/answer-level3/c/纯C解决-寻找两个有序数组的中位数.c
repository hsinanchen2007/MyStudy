### 解题思路
这是一种不是二分查找的O(logn)的效率查找方式
### 代码

```c

double getK(int *nums1,int nums1Size,int *nums2,int nums2Size,int k)//查找到两个数组中第K大
{
    //先解决其中一个数组为空的情况
    if(nums2Size==0)
    return nums1[k-1];
    if(nums1Size==0)
    return nums2[k-1];
    int index1=-1,index2=-1;
    //删除一定不会存在的区间
    if(nums1Size+1<k)
    {
        index2+=(k-nums1Size);
        k=k-index2;
        index2--;
    }
    if(nums2Size+1<k)
    {
        index1+=(k-nums2Size);
        k=k-index1;
        index1--;
    }
    //减半筛选
    while(k>1)
    {
        if(nums1[index1+k/2]<nums2[index2+k/2])
        {
            index1+=k/2;
            k-=k/2;
        }
        else
        {
            index2+=k/2;
            k-=k/2;
        }
    }
    //排除其中一个数组已经全部判断完毕
    if(index1==nums1Size-1)
    {
        index2=index2+1;
        return (double)nums2[index2];
    }
    if(index2==nums2Size-1)
    {
        index1=index1+1;
        return nums1[index1];
    }
    //两个数组都未判断完
    index1=index1+1;
    index2=index2+1;
    if(nums1[index1]<nums2[index2])
    return nums1[index1];
    return nums2[index2];
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int k1=(nums1Size+nums2Size+1)/2;
    int k2=(nums1Size+nums2Size+2)/2;
    return (getK(nums1,nums1Size,nums2,nums2Size,k1)+getK(nums1,nums1Size,nums2,nums2Size,k2))/2;
}
```