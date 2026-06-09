每次都寻找下次能跳跃的最远处，然后更新状态
```
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int S = nums.size();
        int step = 1;
        int prev = 0;
        int curr = nums[0];
        while (curr < S - 1) {
            ++step;
            int new_curr = curr;
            // 寻找下次能跳跃的最远处
            for (int i = prev + 1; i <= curr; ++i)
                new_curr = max(new_curr, i + nums[i]);
            prev = curr;
            curr = new_curr;
        }
        return step;
    }
};
```
