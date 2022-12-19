### 解题思路
把n级台阶时的跳法看出n的函数，记为f(n)。当n>2时，第一次跳的时候就有两种不同的选择：
一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数目，即为f(n-1)；
二是第一次跳2级，此时跳法数目等于剩下的n-2级台阶的跳法数目，即为f(n-2.
因此，n级台阶的不同跳法的总数f(n)=f(n-1)+f(n-2);
于是此问题转换为求斐波那契数列问题。
### 代码

```cpp
class Solution {
public:
	int m = 1e9 + 7;
	int numWays(int n) {
		vector<int> dp(n + 1, -1);
		return Ways(n, dp);
	}
	int Ways(int n, vector<int>& dp)
	{
		//递归边界
		if (n == 0 || n == 1) return 1;
		//状态转移方程
		if (dp[n] != -1) return dp[n];
		else
		{
			dp[n] = (Ways(n-1,dp) + Ways(n-2,dp))%m;
			return dp[n];
		}
	}
};
```