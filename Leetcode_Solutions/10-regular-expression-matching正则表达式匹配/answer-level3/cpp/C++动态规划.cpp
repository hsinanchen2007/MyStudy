## 分类
分类可能比较乱，但是好理解：
p[i][j]表示s的前i个字符和模式串p的前j个字符是否匹配
p[0][j]表示s的前0个字符和模式串前j个字符是否匹配，显然p[0][0] = true;
如果p中出现连续非星号，则往后的p[0][j]都是false
看p[i][j]，为了让p[i][j]为true
**若p[i-1][j-1]=true，则当s[i-1]==p[j-1]或p[j-1]=='.'**，
* 情况1：i-1:a j-1:ab\* i:ab j:ab\*.
* 情况2：i-1:a j-1:a i:ab j:ab
* 情况3：i-1:a j-1:b\*a i:aa j:b\*a\*，这个可以归类到p[i-1][j]=true中去处理
* 情况4：i-1:空 j-1:空

**若p[i-1][j]=true，则当p[j-1]=='*'且(p[j-2]==s[i-1]或p[j-2]=='.')**
* 情况1：i-1:a j:ab\* i:ab j:ab\*
* 情况2：i-1:a j:a.\* i:ab j:a.\*
* 情况3：i-1:a j:ab
* 情况4：i-1:a j:b\*. i:

**若p[i][j-1]=true，则当p[j-1]=='*'时为true**
i空，j-1空不可能出现，已经初始化好了，j-1空也不可能出现，这样就不满足p[i][j-1]=true
* 情况1：i:a j-1:a i:a j:a\*
* 情况2：i:a j-1:a\* 这就不可能为true了
* 情况3：i:a j-1:.\*. i:a j:.\*.\*

**若p[j-1]=='*'，则dp[i][j-2]为true即可**

**代码如下**：
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
    	int slen = s.size(), plen = p.size();
        vector<vector<bool> >dp(slen + 1);
        for (int i = 0; i < slen + 1; ++i) {
        	dp[i].resize(plen + 1);
		}
		dp[0][0] = true;
		for (int i = 1; i <= slen; ++i) {
			dp[i][0] = false;
		}
		bool flag = true;
		for (int j = 1; j <= plen; ++j) {
			if (flag == false) dp[0][j] = false;
			else if (p[j - 1] == '*') dp[0][j] = true;
			else if (p[j - 1] != '*') {
				dp[0][j] = false;
				if (j - 2 >= 0 && p[j - 2] != '*') flag = false;
			}
		}
		for (int i = 1; i <= slen; ++i) {
			for (int j = 1; j <= plen; ++j) {
				dp[i][j] = (dp[i-1][j-1]==true && (s[i-1]==p[j-1] || p[j-1] == '.'))
						||	(dp[i-1][j] == true && p[j-1]=='*' && (p[j-2]==s[i-1] || p[j-2] == '.'))
						|| (dp[i][j-1] == true && p[j-1] == '*') 
						|| (p[j-1]=='*' && dp[i][j-2]);
			}
		}
		return dp[slen][plen];
    }
};
```