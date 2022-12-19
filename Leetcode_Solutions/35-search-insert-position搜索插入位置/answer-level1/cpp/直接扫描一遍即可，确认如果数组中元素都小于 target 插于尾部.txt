### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
            if (target < nums[i]) {
                auto iter = nums.begin();
                nums.insert(iter + i, target);
                return i;
            }
        }
        // nums.push_back(target);
        return nums.size();
    }
};
```