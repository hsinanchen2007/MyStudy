### 解题思路
【先赞后看，养成习惯】
关于**动态规划**，作者最近也做了一部分题目，对**动态规划**有了一点自己的理解。

**动态规划**归根结底就是一个将**状态空间**遍历的过程，试想如果我有整个状态空间的值，那么你问我一个状态，我都可以立刻把对应的值告诉你，这将多么有趣呀！

**状态空间**：这里我们就得首先明确有哪些状态，状态赋予的含义是什么。所以每次写`动态规划`的题解的时候，都要明确`状态`。

**如何遍历状态空间**：这里的遍历是一种有限的遍历，遍历到你问我的状态对应的值即可，并不是真的需要我们把各种各样的情况全部算完之后才结束（这样也是省时省力嘛）。
 - 初始状态：初始状态一般都较为简单，可以根据题意直接写出来。
 - 状态转移方程：方程是否能写出来，与**状态定义**密切相关，状态定义过于简单，转移方程往往很难写出；定义过于繁琐，转移方程又会复杂度极高。（这里我目前还没有统一的框架，只能说根据不同的题目进行判断）


下面是本道题的题解
### 状态定义
`dp[i][0]`:表示长度为i，且第i个字符是`a`的时字符串数
`dp[i][1]`:表示长度为i，且第i个字符是`e`的时字符串数
`dp[i][2]`:表示长度为i，且第i个字符是`i`的时字符串数
`dp[i][3]`:表示长度为i，且第i个字符是`o`的时字符串数
`dp[i][4]`:表示长度为i，且第i个字符是`u`的时字符串数

### 状态转移
$$

\begin{cases}
dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4]\\
dp[i][1] = dp[i - 1][0] + dp[i - 1][2]\\
dp[i][2] = dp[i - 1][1] + dp[i - 1][3]\\
dp[i][3] = dp[i - 1][2]\\
dp[i][4] = dp[i - 1][2] + dp[i - 1][3]
\end{cases}
$$
<![幻灯片6.PNG](https://pic.leetcode-cn.com/b361ef3f22fac8f2266a5cb8db5151686000aeb4bb7d9416714ab6589298998e-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/9103ced83abf9f56ecd48da15ccb3f8795e28e759737549c19758b6c2e374e71-%E5%B9%BB%E7%81%AF%E7%89%877.PNG),![幻灯片8.PNG](https://pic.leetcode-cn.com/d1fe833078623dc6015e452452c30c06f3d7dbd8df5d24c73db3eec5bc5faaf1-%E5%B9%BB%E7%81%AF%E7%89%878.PNG),![幻灯片9.PNG](https://pic.leetcode-cn.com/42443b76faca6fa79cae1ba719a0925da29678569b7244efd51d28484bfd5d73-%E5%B9%BB%E7%81%AF%E7%89%879.PNG)>

### 相关题目
[LeetCode935 骑士拨号器](https://leetcode-cn.com/problems/knight-dialer/)


### 我的题解
[LeetCode1262 可被三整除的最大和](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/)
[LeetCode688 “马”在棋盘上的概率](https://leetcode-cn.com/problems/knight-probability-in-chessboard/solution/zhuang-tai-ji-de-zai-ci-ying-yong-by-christmas_wan/)
[LeetCode967 连续差相同的数字](https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences/solution/cun-chu-kong-jian-ke-bian-de-dpshu-zu-by-christmas/)
[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/solution/zhuang-tai-ding-yi-hen-shi-zhong-yao-by-christmas_/)
[LeetCode1218 最长定差子序列](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/solution/yi-dao-jian-dan-de-dong-tai-gui-hua-de-you-hua-wen/)
[LeetCode523 连续子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/solution/qian-zhui-he-yu-intmapde-zai-ci-ying-yong-by-chris/)
[LeetCode576 出界的路径数](https://leetcode-cn.com/problems/out-of-boundary-paths/solution/zhuang-tai-ji-du-shi-zhuang-tai-ji-by-christmas_wa/)

### 代码

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
      if (n == 1) {
		return 5;
	}
	int MOD = 1000000007;
	vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(5));
	for (int i = 0; i < 5; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % MOD + dp[i - 1][4]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
		dp[i][3] = (dp[i - 1][2]) % MOD;
		dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
	}
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum = (sum + dp[n - 1][i]) % MOD;
	}
	return sum;
    }
};
```