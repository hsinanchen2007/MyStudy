### 解题思路
设dp1(a,b)为从a到b取数所需要最少金额，可以得到状态转移关系dp1(a,b)=min(max(dp1(a,m-1),dp1(m+1,b))+m);(a<=m<=b)，m为当前所猜的数,构建dp数组存取某个状态的解，防止重复计算同一解。递归的边界为2种情形，a>=b,dp1(a,b)=0;a==b-1,dp1(a,b)=a.

### 代码

```cpp
class Solution {
public:
const int maxm2 = pow(2, 31) - 1;
int dp1(int start, int end, int**dp)
{
	if (start >= end)
		return 0;
	if (start == end - 1)
		return start;
	if (dp[start][end] != -1)
		return dp[start][end];
	int res;
	int min= maxm2;
	int a, b;
	for (int i = start; i <= end; i++)
	{
		a = dp1(start, i - 1, dp);
		b = dp1(i + 1, end, dp);
		res = i + (a > b ? a : b);
		if (res < min)
			min = res;
	}
	dp[start][end] = min;
	return min;
}
    int getMoneyAmount(int n) {
    int**dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)dp[i][j] = -1;
	}
	return dp1(1, n, dp);
    }
};
```