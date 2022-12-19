```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0; // 能走到的最大位置

        for (int i = 0; i < nums.size(); ++i) {
            if (i <= mx && (i + nums[i]) > mx) mx = (i + nums[i]);
        }
        return mx >= nums.size() - 1;
    }
};
```