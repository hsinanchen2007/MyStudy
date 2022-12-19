### 解题思路

我看很多答案提到回溯法，回溯法的优点在于空间复杂度是线性的，但是如果没有很好的剪枝策略，时间复杂度很高
其实一开始我想的是动态规划算法，如果这道题要求输出一共有多少种解，那DP妥妥没问题，但是这次要列出所有解，如果直接用DP的话，空间复杂度会很高
所以我想了一个结合回溯和DP的方法
回溯法最大的问题就是，当你已经选了一个集合{s1, s2, ..., si-1}的时候，你不知道第i个元素选择之后是否能得到最终结果
所以可以用DP先打表，`table[i][j]`就表示在1 ~ n的数字中，只使用i ~ n的元素，能否凑出数值j
这个打表过程类似于完全背包问题，唯一要注意的是这个表要从后往前递推
有了这个表之后就可以遍历了，用一个数组记录已经选择的数字，然后用一个整数value记录到目前为止已经凑出的数值
考虑第i个元素，如果`table[i][target - (value + num[i])] == true`，说明把第i个元素选入之后，剩下i ~ n的元素依然可以凑出target，反之回溯
个人认为这样的剪枝效率应该是比较高的


### 代码

```cpp
class Solution {
public:
    template <typename T>
    struct Matrix
    {
	vector<T> data;
	int m, n;
	Matrix(int _m, int _n) : m(_m), n(_n), data(_m * _n, T()) {}
	inline T& operator()(int i, int j) { return data[i * n + j]; }
	inline const T& operator()(int i, int j) const { return data[i * n + j]; }
    };

    vector<vector<int>> combinationSum(vector<int>& num, int n) {
	int m = num.size();

	// =============== DP ===============
	Matrix<char> mat(m, n + 1);
	for (int i = 0; i < m; ++i) mat(i, 0) = 1;
	for (int j = num[m - 1]; j <= n; j += num[m - 1]) mat(m - 1, j) = 1;
	for (int i = m - 2; i >= 0; --i) {
		for (int j = 1; j <= n; ++j) {
			mat(i, j) = mat(i + 1, j) || (j - num[i] >= 0 ? mat(i, j - num[i]) : 0);
		}
	}

	vector<vector<int>> rst;

	// =============== 遍历 ===============
	int value = 0;
	vector<int> stat = {0};
	while (true) {

		if (value == n) {
			rst.push_back(vector<int>(stat.size() - 1));
			for (int i = 0; i < stat.size() - 1; ++i) {
				rst.back()[i] = num[stat[i]-1];
			}
			stat.pop_back();
			value -= num[stat.back() - 1];
		}

		int k = stat.back();
		if (k == m) {
			stat.pop_back();
			if (stat.empty()) break;
			value -= num[stat.back() - 1];
		}
		else {
			++stat.back();
			int val = value + num[k];
			if (n - val >= 0 && mat(k, n - val)) {
				stat.push_back(k);
				value += num[k];
			}
		}
	}
	
	return rst;
    }
};
```