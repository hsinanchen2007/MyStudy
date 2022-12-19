# 题目
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

```
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```
# 思路
官方解题方式，前向双指针，C++版本

# 解答
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  //前向双指针
        int p1=0;
        int p2=0;
        int p=0;
        vector<int> nums1_copy=nums1;
        while(p1<m&&p2<n)
        {
            nums1_copy[p1]<nums2[p2] ? nums1[p++]=nums1_copy[p1++] : nums1[p++]=nums2[p2++];
        }
        
        //处理其余数据
        if(p1 < m)
            copy(nums1_copy.begin()+p1,nums1_copy.begin()+m,nums1.begin()+p);
        if(p2 < n)
            copy(nums2.begin()+p2,nums2.begin()+n,nums1.begin()+p);

        
    }
};
```
