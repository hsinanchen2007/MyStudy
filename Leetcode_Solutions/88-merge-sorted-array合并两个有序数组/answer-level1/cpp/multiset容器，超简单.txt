### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> a;
        for (int i = 0; i < m; i++)
            a.insert(nums1[i]);
        for (int i = 0; i < n; i++)
            a.insert(nums2[i]);
        nums1.clear();
        for (auto i = a.begin(); i != a.end(); i++)
            nums1.push_back(*i);
    }
};
```