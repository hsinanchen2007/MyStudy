### 解题思路
1. for (int i = 0; i <= end; ++i)   // 此处i是小于end，不是小于nums.size()
2. if (end >= nums.size()-1)        // 此处end是大于nums.size()-1)，不是大于nums.size()
因为之前ac过一次，第二次做时没有仔细思考。
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (!nums.size()) return true;
        int end = 0;
        for (int i = 0; i <= end; ++i) {
            end = max(end, nums[i] + i);
            if (end >= nums.size()-1) return true;
        }
        return false;
    }
};
```