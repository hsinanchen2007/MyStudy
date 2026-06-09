### 解题思路
本题主要思路为动态规划,状态转移方程如下
$$
dp[n] =
\begin{cases}
1, & \text{n = 2}  \\
2, & \text{n = 3}  \\
max(dp[n-2]*2,dp[n-3]*3), & \text{n > 3}
\end{cases}
$$

注意特殊情况n=2,3时的处理，因为至少拆分为两个正整数

### 代码

```cpp
class Solution {
public:
	int integerBreak(int n) {
		vector<int> nums(n + 3);
		for (size_t i = 0; i < n + 3; i++)
		{
			if (i <= 3)
				nums[i] = i;
			else
				nums[i] = max(nums[i - 2] * 2, nums[i - 3] * 3);
		}
		nums[2]--;
		nums[3]--;
		return nums[n];
	}
};
```