### 解题思路

C++标准库应用。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iter = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), iter);
    }
};
```