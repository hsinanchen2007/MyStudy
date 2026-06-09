### 解题思路
双指针，从后向前扫描。

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end=m+n;
        while (m||n) {
            if (m && n) {
                if (nums1[m-1]>nums2[n-1]) nums1[--end]=nums1[--m];
                else nums1[--end]=nums2[--n];
            } else if (m) {
                nums1[--end]=nums1[--m];
            } else if (n) {
                nums1[--end]=nums2[--n];
            }
        }
    }
};
```