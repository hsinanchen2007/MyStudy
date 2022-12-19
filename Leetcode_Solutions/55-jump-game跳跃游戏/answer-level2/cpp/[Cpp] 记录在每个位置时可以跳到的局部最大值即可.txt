### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 遍历每个位置记录当前可以跳的最远距离，判断是否有最远距离到达或超过最后一个位置
        if (nums.size() <= 1) return true;
        int max_jump = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (max_jump < i) return false;
            max_jump = max(max_jump, i + nums[i]);
            if (max_jump >= nums.size() - 1) return true;
        }
        return false;
    }
};
```