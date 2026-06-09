
动态规划最重要的是定义状态。

定义状态的时候需要分析问题的自变量和因变量。本问题受到两个因素影响，是否打劫和当前房子位置。

状态数组定义为: DP[i][j], i房子, j是否偷窃

状态转移方程为:

- DP[i][0] = max(DP[i-1][1], DP[i-1][0]); //当前不偷，意味着之前偷了，或者之前没有偷，选择其中最佳的状态
- DP[i][1] = DP[i-1][0] + a[i]; // 当前偷，也就是之前不偷 加上当期偷的情况

代码如下:

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0 ) return 0;
        vector<vector<int>> DP(nums.size(), vector<int>(2,0));

        DP[0][0] = 0;
        DP[0][1] = nums[0];

        for (int i = 1; i < nums.size(); i++){
            DP[i][0] = max(DP[i-1][1], DP[i-1][0]);
            DP[i][1] = DP[i-1][0] + nums[i];
        }
        return max(DP[nums.size()-1][1], DP[nums.size()-1][0]);

    }
};
```