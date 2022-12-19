### 解题思路
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]


### 代码

```cpp
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(nums1.empty()||nums2.empty()) return;
//         int s1=m-1, s2=n-1;
//         for(int k = m+n-1;k>=0;k--){
//             if(s1>=0&&s2<0) return;
//             else if(s1<0&&s2>=0)  nums1[k] = nums2[s2--];
//             else if(nums1[s1]>nums2[s2]) nums1[k] = nums1[s1--];
//             else nums1[k] = nums2[s2--];
//         }
//     }
// };
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s1=m-1, s2=n-1;
        int k = m+n-1;
        while(s1>=0||s2>=0){
            if(s1<0) nums1[k--] = nums2[s2--];
            else if(s2<0) return;
            else
            nums1[k--] = (nums1[s1]>nums2[s2]) ? nums1[s1--]:nums2[s2--]; 
        }
          
    }
};
```