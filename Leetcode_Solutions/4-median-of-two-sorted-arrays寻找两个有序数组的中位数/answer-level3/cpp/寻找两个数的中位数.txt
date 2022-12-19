题目求两个有序数组的中位数，最简单的思路就是把两个有序数组合并成一个有序数组，然后再求中位数。但合并数组需要的时间复杂度为O(m+n),不能满足题目log（m+n）的要求。其实，没有必要对两个数组进行排序，我们只要找出两个数组的中心的位置的数就可以了，为了避免讨论数组长度奇数和偶数，我们令两个数组的中心位置(从1开始计数)为：mid1=(m+n+1)/2,和mid2=(m+n+2)/2。
讨论：
第一种情况：当nums1为空的时候，返回nums2的中位数。
第二种情况，当nums2为空的时候，返回nums1的中位数。
第三种情况，当nums1和nums2都非空的时候，通过递归法来找数组的第k个位置的数。其核心思想就是比较nums1和nums2两个数组在k/2位置数的大小，记为x1，x2。当x1>x2的时候说明中位数不在nums2的前k/2那一部分(这一部分都比第k、2要小），我们把nums2的前k/2位置的数割掉，然后在两个数组剩下的数找第k-k/2大的数即可。同理，当x1<x2说明中位数不在nums1的前k/2部分。


```
class Solution {
public:
    int findKth(const vector<int> &nums1,int i,const vector<int> &nums2,int j,int k)
    {
        int MAX_VALUE =0x7fffffff;
        if(i>=nums1.size()) 
            return nums2[j+k-1];
        if(j>=nums2.size()) 
            return nums1[i+k-1];
        if(k==1) 
            return (nums1[i]<nums2[j])?nums1[i]:nums2[j];
        int x1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:MAX_VALUE;
        int x2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:MAX_VALUE;
        if(x1<x2)
            return findKth(nums1,i+k/2,nums2,j,k-k/2);
        else
            return findKth(nums1,i,nums2,j+k/2,k-k/2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid1=(nums1.size()+nums2.size()+1)/2;
        int mid2=(nums1.size()+nums2.size()+2)/2;
        if(nums1.size()==0)
            return (nums2[mid1-1]+nums2[mid2-1])/2.0;
        else if(nums2.size()==0)
            return (nums1[mid1-1]+nums1[mid2-1])/2.0;
        else
            return (findKth(nums1,0,nums2,0,mid1)+findKth(nums1,0,nums2,0,mid2))/2.0;
    }
};
```
