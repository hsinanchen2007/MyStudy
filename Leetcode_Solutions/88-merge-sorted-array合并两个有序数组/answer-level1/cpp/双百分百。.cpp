### 解题思路
先填满数组1，再排序。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m ;i<nums1.size() ;i++)
        {
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};
```