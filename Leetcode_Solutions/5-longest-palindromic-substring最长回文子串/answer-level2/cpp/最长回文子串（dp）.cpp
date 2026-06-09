### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public: //经过一段时间的学习，此时再看这道题写还是只会暴力解法，但是刚开始看不懂的dp解法现在看的懂了。
   string longestPalindrome(string s) {       //状态转移方程：dp[i][j] = s[i]==s[j]&&s[i+1][j-1]      dp[i][j]为i位置到j位置是否为回文串
	if (s.size() == 0) return s;
	int len = s.length();
	int x = 0, maxlen = 0;          //maxlen为最长回文串的长度，x为最长回文串字符串的开头
	bool dp[len][len];//定义一个二维数组
	for (int j = 0; j < len; j++)
		for (int i = 0; i <= j; i++) {     //注意i在0-j之间
			if (s[i] == s[j]) {            //放在这里可以小小优化一下，从1048ms到880ms
				if (j - i <= 1) {          // if...else...条件为了判断当前i到j位置是否回文
					dp[i][j] = true;
				}
				else {
					/*  不需要这样判断
					if (dp[i + 1][j - 1] == true) {
						dp[i][j] = true;
					}
					*/
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
            else dp[i][j]=false;
			if (dp[i][j] == true) {        //此处的if条件是为了更新maxlen,x,y
				if (maxlen < j - i + 1) {
					maxlen = j - i + 1;
					x = i;
				}
			}

		}
	return s.substr(x, maxlen);            //开头位置加长度就可以截取字符串
}
};
```