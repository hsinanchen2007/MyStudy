# 解法一：
动态规划

```C++ []
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int min_neg = 0;
        int max_pos = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                min_neg = max_pos = 0;
            } else if (nums[i] > 0) {
                max_pos = max(max_pos * nums[i], nums[i]);
                min_neg = min_neg * nums[i];
            } else {
                int t = max_pos;
                max_pos = min_neg * nums[i];
                min_neg = min(t * nums[i], nums[i]);
            }
            res = max(res, max_pos);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/75ee950f4cb795651ec73a2c4b052e0f2e26716fc9aceef16e45ffe3af80fb92-image.png)

# 解法二：
双向遍历

```C++ []
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int left_max = 1;
        for (int i = 0; i < nums.size(); ++i) {
            left_max *= nums[i];
            res = max(res, left_max);
            left_max = (left_max == 0) ? 1 : left_max;
        }
        int right_max = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            right_max *= nums[i];
            res = max(res, right_max);
            right_max = (right_max == 0) ? 1 : right_max;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/48696b95d8757e20b434dd4834600d6cd594ef16e2fdea2a516fd84314d82b52-image.png)
