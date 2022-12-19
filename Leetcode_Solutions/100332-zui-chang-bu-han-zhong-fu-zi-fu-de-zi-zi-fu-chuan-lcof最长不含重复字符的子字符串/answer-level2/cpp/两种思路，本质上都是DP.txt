# 先想到动态规划，后想到滑动窗口
滑动窗口本质上是一维动态规划。

## 思路一：二维动态规划（时间超限）
**一看到这种题就想列一波状态转移方程**：
定义`dp[i][j]`表示下标`i`到下标`j`的子串是否不含重复元素。
* 初始化：当`i==j`时，`dp[i][j]`是真（一个元素当然不重复）
* 状态转移：`dp[i][j]`是真，则要求`dp[i][j-1]`是真，并且`dp[i+1][j]`也是真，这是显而易见的；
其次还要求`s[i]!=s[j]`。因为当满足前两个条件时，`s[i]`、`s[j]`一定不在下标从`i+1`到`j-1`的子串中，如果这时再满足`s[i]!=s[j]`，那么`dp[i][j]`一定是真。
因此状态转移方程为`dp[i][j] = (dp[i][j-1] && dp[i+1][j] && s[i] != s[j]);`

动态规划代码如下：
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	size_t len = s.size();
    	if (len == 0) return 0;
    	int res = 1;
        vector<vector<bool> > dp(len, vector<bool>(len, true));
        for (int i = len - 2; i >= 0; --i) {
        	for (int j = i + 1; j < len; ++j) {
        		dp[i][j] = (dp[i][j-1] && dp[i+1][j] && s[i] != s[j]);
        		if (dp[i][j] && j - i + 1 > res) res = j - i + 1;
			}
		}
		return res;
    }
};
```
时间复杂度、空间复杂度均为$O(n^2)$，

## 思路二：滑动窗口
其实就是两个下标`i`，`j`，一个指向当前子字符串开头，另一个指向当前子字符串结尾。用map存储当前子串中各个字母出现的数。试探性`++j`，如果`s[j]`出现次数达到2，要不断`++i`以使得`s[j]`出现次数为1。过程中的最长子串长度作为返回值即可。
正确性证明：**本质上也是动态规划**。状态转移方程一列就懂了————
`dp[i]`表示以`s[i]`结尾的最长不重复子序列长度，那么：
`dp[i]=dp[i-1]中要求左端增加到不存在s[i]之后的长度+1`; 这也是可以安心`++i`的原因
```cpp
class Solution {
    int lengthOfLongestSubstring(string s) {
    	size_t len = s.size();
    	if (len == 0) return 0;
    	int res = 1;
        int i = 0, j = 0;
		map<char, int> mp; 
        for (; j < len; ++j) {
        	mp[s[j]]++;
        	if (mp[s[j]] == 1) {
        		if (j - i + 1 > res) res = j - i + 1;
        		continue;
        	}
        	if (j == len - 1) break;
        	while (mp[s[j]] > 1) {
        		mp[s[i]]--;
        		++i;
			}
		}
		return res;
    }
};
```
时间复杂度$O(n)$，但map红黑树实现$logn$，综上$O(nlogn)$
