### 解题思路

没思路，然后看了**官方题解：**https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/

这里就不复述具体的解题思路了，不太好描述清楚，官方题解中有动画演示，讲的很清晰。

附上官方题解中的状态转移方程：
$$
dp[i] = \text{max}(dp[j]) + 1, \text{其中} \, 0 \leq j < i \, \text{且} \, \textit{num}[j]<\textit{num}[i]
$$
`dp[i]`为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度。

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();//nums[]的长度
        if (n == 0)
            return 0;
        //dp[i]保存从nums[0]到nums[i]的子序的最长上升子序的长度
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;//默认为1即假设前面的元素中没有大于nums[i]的元素
            //遍历nums[i]之前的元素
            for (int j = 0; j < i; j++) {
                //只要有比nums[i]小的元素，就要更新dp[i]
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());//返回数组dp[]中的最大值
    }
};
```