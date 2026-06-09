C++的超简洁解法
STL万岁！
```cpp []
#include <algorithm>

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto [beg, end] = equal_range(nums.begin(), nums.end(), target);
        if (beg == nums.end() || *beg != target) return {-1, -1};
        return {beg - nums.begin(), end - nums.begin() - 1};
    }
};
```