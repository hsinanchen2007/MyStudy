### 解题思路
仿照std::unique实现

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        auto result = nums.begin();
        for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter)
        {
            if (*result != *iter && ++result != iter)
                *result = *iter;
        }

        return std::distance(nums.begin(), ++result);
    }
};
```