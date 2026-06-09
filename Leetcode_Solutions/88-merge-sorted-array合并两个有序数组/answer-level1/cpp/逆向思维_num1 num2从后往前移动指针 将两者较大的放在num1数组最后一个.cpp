### 解题思路
此处撰写解题思路
https://leetcode.com/problems/merge-sorted-array/discuss/29515/4ms-C%2B%2B-solution-with-single-loop
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            // nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[tar--] = nums1[i--];
            }else{
                nums1[tar--] = nums2[j--];
            }
        }
    }
};
```