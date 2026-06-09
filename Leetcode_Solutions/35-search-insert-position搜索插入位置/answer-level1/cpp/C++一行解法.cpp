### 解题思路
用lower_bound函数找到插入位置的迭代器减去nums.begin()即为答案。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};
```