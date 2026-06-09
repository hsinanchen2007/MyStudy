### 解题思路
需要学会使用c++ STL中vector容器的删除、插入、排序函数进行操作。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.end()-n,nums1.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        
    }
};
```