### 解题思路
1.先将两个数组合并，在使用sort算法将两个数组排序。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m,j = 0; i < m + n,j < n; i++,j++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};
```