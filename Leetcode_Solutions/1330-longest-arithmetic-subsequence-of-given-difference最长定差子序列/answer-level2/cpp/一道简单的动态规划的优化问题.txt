### 解题思路
【先赞后看，养成习惯】
**不知道大家做着道题的感觉如何，反正我做的时候感受还是蛮多的，所以就想写一篇题解留下自己的理解。**
题目是常规的动态规划的题目，无论是从`状态定义`还是从`状态转移方程`的书写，都是十分正常的题目，但这道题与众不同的是在`代码书写`方面，有一个**循序渐进的优化过程**，而这一过程我认为在**思考过程**中是十分重要的
### 状态定义
`dp[i]`：表示arr[0...i]的定差子序列的最大长度

### 状态转移
根据上述的`状态定义`，我们可以写出如下定义
`dp[i]`表示arr[0...i]的定差子序列的最大长度
`dp[j]`表示arr[0...j]的定差子序列的最大长度

**Note:** 子序列是不连续的，子数组是连续的

如果`arr[i]`，`arr[j]`存在以下关系
$$
arr[i] - arr[j] == difference
$$
则有
$$
dp[i] = max(dp[i],dp[j] + 1)
$$
综合上述，我们写出如下式子
$$
dp[i] = \max \limits_{arr[i] - arr[j] == difference}(dp[i],dp[j] + 1)  
$$
### 如何优化
**以上过程显得索然无味**，但是本题才刚刚开始。（如果有兴趣可以尝试做一做`相关题目`，思路与下述过程类似）


根据上述分析过程，我们可以快速写出如下代码（**核心部分**）
```cpp
for (int i = 1; i < n; i++) {
	for (int j = 0; j < i; j++) {
		if (arr[i] - arr[j] == difference) {
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}
}
```
但是`Time Limit Erro`，分析时间复杂度大概是O(n*n)的水平

这里不由得想到了优化寻找过程，即使用`intMap`来作为`键值`到`键`的映射
（`intMap`可以参考`我的题解`[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/solution/zhuang-tai-ding-yi-hen-shi-zhong-yao-by-christmas_/)）

然而针对如下测试用例，仅仅使用`unorder_map<int,int>`的数据结构是不行的，因为有重复的键值对应不同的键，因次再次改进为`unorder_map<int,vector<int>>`
$$
vector<int> arr = { 4,12,10,0,-2,7,-8,9,-9,-12,-12,8,8 };
$$
$$
difference =  0;
$$

### 相关题目
[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/)
### 我的题解
[LeetCode1262 可被三整除的最大和](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/)
[LeetCode688 “马”在棋盘上的概率](https://leetcode-cn.com/problems/knight-probability-in-chessboard/solution/zhuang-tai-ji-de-zai-ci-ying-yong-by-christmas_wan/)
[LeetCode967 连续差相同的数字](https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences/solution/cun-chu-kong-jian-ke-bian-de-dpshu-zu-by-christmas/)
[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/solution/zhuang-tai-ding-yi-hen-shi-zhong-yao-by-christmas_/)
### 代码

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       int n = arr.size();
	if (n == 0) { return 0; }
	vector<int> dp(n, 1);
	dp[0] = 1;
	int MAX = 1;
	unordered_map<int, vector<int>> intMap;
	for (int i = 0; i < n; i++) {
		intMap[arr[i]].push_back(i);
	}

	for (int i = 1; i < n; i++) {
		if (intMap.count(arr[i] - difference) ) {
			for (auto iter = intMap[arr[i] - difference].begin(); iter != intMap[arr[i] - difference].end(); iter++) {
				int index = *iter;
				if (index < i) {
					dp[i] = max(dp[i], dp[index] + 1);
				}
			}
		}
		MAX = max(MAX, dp[i]);
	}

	return MAX;
    }
};
```