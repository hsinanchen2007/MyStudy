### 动态规划
文首推荐LeetCode官方题解：[Palindrome Partitioning III - LeetCode官方题解 - 动态规划](https://leetcode-cn.com/problems/palindrome-partitioning-iii/solution/fen-ge-hui-wen-chuan-iii-by-leetcode/)

我也是在看了题目描述下的提示1之后才想到解法的。
1. 首先计算出子串变成一个回文串需要修改的次数。
	 - `subPalindrome[l][r]`表示子串`s[l,r]`变成回文串需要修改的次数；
	 - 初始态1：仅一个字符时，`subPalindrome[i][i]`等于0，无需做修改；
	 - 初始态2：相邻2个字符时，如果不相等，则需要修改其中一个；如果相等，则无需做修改；
	 - 状态转移方程是：`subPalindrome[l][r] = subPalindrome[l+1][r-1] + (s[l] != s[r])`；
	 - 由上面的状态转移方程可以看出，我们需要先计算出长度短的子串的修改次数，然后再计算长度长的。
2. 有了前面计算好的子串变成回文串的修改次数`subPalindrome`之后，接下来继续使用动态规划解决字符串划分成`k`个回文串。
	 - `dp[i][j]`表示前`i+1`个字符（`s[0~i]`）拆分成`j+1`个回文串所需要的最小修改次数；
	 - 初始态：仅拆分成一个回文串时，`dp[i][0]`等于`subPalindrome[0][i]`；
	 - 状态转移方程是：`dp[i][j] = min(dp[i0][j-1] + subPalindrome[i0+1][i])`，其中`j-1 <= i0 < i`。

最终代码实现如下：
```
class Solution {
public:
	int palindromePartition(string s, int k) {
		// 子串变成回文串所需修改的次数；初始化为0；仅一个字符时不需要修改即为回文串
		vector<vector<unsigned>> subPalindrome(s.size(), vector<unsigned>(s.size(), 0));
		// 相邻2个字符时，如果不相等，则修改数量等于1
		for (size_t i = 0; i < s.size() - 1; ++i) {
			if (s[i] != s[i + 1])
				subPalindrome[i][i + 1] = 1;
		}

		// 如果s[l]等于s[r]，则sub[l][r]变成回文串所需的修改次数等于sub[l+1][r-1]修改次数
		// 如果s[l]不等于s[r]，则sub[l][r]变成回文串所需的修改次数等于sub[l+1][r-1]修改次数加1
		for (size_t len = 3; len <= s.size(); ++len) {
			for (size_t nLeftIdx = 0; nLeftIdx <= s.size() - len; ++nLeftIdx) {
				size_t nRightIdx = nLeftIdx + len - 1;
				subPalindrome[nLeftIdx][nRightIdx] = subPalindrome[nLeftIdx + 1][nRightIdx - 1] + (s[nLeftIdx] != s[nRightIdx]);
			}
		}

		// dp[i][j]表示前i+1个字符（0~i）拆分成j+1份所需要的最小修改次数
		vector<vector<unsigned>> dp(s.size(), vector<unsigned>(k, s.size()));
		for (size_t i = 0; i < s.size(); ++i) {
			// 前i+1个字符(0~i)分成1份的修改次数即为subPalindrome[0][i]
			dp[i][0] = subPalindrome[0][i];
			for (size_t j = 1; j < std::min(i + 1, size_t(k)); ++j) {
				// 状态转移方程：dp[i][j] = min(dp[k][j-1] + subPalindrome[k+1][i], j-1<=k<i);
				for (size_t k = j - 1; k < i; ++k)
					dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + subPalindrome[k + 1][i]);
			}
		}

		return dp[s.size() - 1][k - 1];
	}
};
```