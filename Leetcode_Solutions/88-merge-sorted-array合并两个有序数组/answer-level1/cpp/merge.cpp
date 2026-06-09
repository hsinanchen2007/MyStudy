### 解题思路
执行用时:0 ms, 在所有 C++ 提交中击败了100.00%的用户
思路十分简单,先合并再排序
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.begin() + m + n, [](int x, int y) -> bool {
            return x < y;
        });
    }
};
```