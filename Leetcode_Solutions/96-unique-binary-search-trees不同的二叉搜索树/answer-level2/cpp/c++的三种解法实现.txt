
```
// 递归方法，超时
class Solution_Recursion {
public:
	int numTrees(int n) {
		if (n <= 1)
			return 1;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += numTrees(i - 1) * numTrees(n - i);
		}
		return res;
	}
};

// 带备忘录的动态规划方法
class Solution_memoDP {
public:
	int numTrees(int n) {
		if (n <= 1) return 1;
		vector<int> memo(n + 1, 1);
		for (int i = 2; i <= n; ++i) {
			int res = 0;
			for (int j = 1; j <= i; ++j) {
				res += memo[j - 1] * memo[i - j];
			}
			memo[i] = res;
		}
		return memo[n];
	}
};

// 数学方法
class Solution {
public:
	int numTrees(int n) {
		long long C = 1;
		for (int i = 0; i < n; ++i) {
			C = C * 2 * (2 * i + 1) / (i + 2);
		}
		return (int)C;
	}
};
```
