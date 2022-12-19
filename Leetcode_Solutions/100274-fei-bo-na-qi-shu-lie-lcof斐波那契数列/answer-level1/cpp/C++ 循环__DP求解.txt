

### 代码

```cpp
//动态规划求解
class Solution {
public:
	const int m = 1e9 + 7;
	int fib(int n) {
		vector<int> dp(n + 1, -1);
		return solve(n, dp);
	}
	int solve(int n, vector<int>& dp) {
		//递归边界
		if (n == 0 || n == 1) return n;
		//状态方程
		//如果该值已被计算过，则直接返回计算的值
		if (dp[n] != -1) return dp[n];
		else//重新进行计算
		{
			dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % m;
			return dp[n];
		}
	}
};
```

```cpp

/*循环求解*/
class Solution {
public:
	int fib(int n) {
		int m = 1e9 + 7;
		if (n == 0 || n == 1) return n;//特殊情况处理
		int firstNumber = 0;//记录前一个值
		int secondNumber = 1;//记录后一个值
		int num;
		for (int i = 2; i <= n; i++)
		{
			num = (firstNumber + secondNumber ) % m;
			firstNumber = secondNumber;
			secondNumber = num;
		}
		return num;
	}
};
```