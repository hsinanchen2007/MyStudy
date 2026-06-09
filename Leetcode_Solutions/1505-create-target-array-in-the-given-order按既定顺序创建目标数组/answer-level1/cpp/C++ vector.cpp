### 解题思路
NA

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        const auto size = nums.size();
        for (int i = 0; i < size; i++) {
            auto it = res.begin() + index[i];
            res.insert(it, nums[i]);
        }
        return res;
    }
};
```