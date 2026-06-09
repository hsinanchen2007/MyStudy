### 解题思路
动态规划的思路很多人已经说的很清楚了。

注意遇到nums[i]时，要乘以dp[i-1]的min来算出最大值（需要再跟nums[i]比较再取最大值），乘以dp[i-1]的max来算出最小值（需要再跟nums[i]比较取最小值）。

没有节省内存用三个变量来代替，是想写得贴近本质、清楚一点。
### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] >= 0) {
                dp_max[i] = max(nums[i] * dp_max[i-1], nums[i]);
                dp_min[i] = min(nums[i] * dp_min[i-1], nums[i]);
            } else {
                dp_max[i] = max(nums[i] * dp_min[i-1], nums[i]);
                dp_min[i] = min(nums[i] * dp_max[i-1], nums[i]);
            }
        }

        int result = dp_max[0];
        for (int i = 0; i < dp_max.size(); ++ i) {
            result = max(result, dp_max[i]);
        }
        return result;
    }
};
```
![微信图片_20200112143833.png](https://pic.leetcode-cn.com/0abaf32102457b64530d749462c215534972566c3038251678f2dbfae0226554-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200112143833.png)

