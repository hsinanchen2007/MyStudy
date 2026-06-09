每次都从可遍历的位置中找能向前跳远到最远位置的点来更新状态。
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
        int left = 0;
        int right = nums[0];
        int N = nums.size();
        while (right < N - 1) {
            int t = right;
            for (int i = left + 1; i <= right; ++i) {
                t = max(t, i + nums[i]);
            }
            if (t == right) return false;
            left = right;
            right = t;
        }
        return true;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a68c24d8e7bbef9a160e8dd57ad481e02622106409bca0e2c5f50621ce2bec82-image.png)
