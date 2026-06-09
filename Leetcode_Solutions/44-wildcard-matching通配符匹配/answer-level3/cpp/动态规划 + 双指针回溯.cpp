### 解题思路
动态规划
1.当s[i - 1] == p[j - 1] || p[j - 1] == '?'时，也就是字符匹配或者p[j-1]为'?'通配，dp[i][j] = dp[i - 1][j - 1]。

2 当p[j-1]为x时，有两种情况，(x->*)
   2.1第一种是用x做空字符串,相当于这个x没有了,dp[i][j]=dp[i][j-1];前面的若是匹配上了，那就不管我目前这个x的事情了
   eg: abcd 和 abcdx 在这里前面四个都匹配上了，那我就可以当做空串直接匹配
   2.2用做很多个，这时候可能遇到的困难是考虑到x可能匹配多个字符串，因此我们只需要判断dp[i-1][j]是否匹配，因为x能匹配一切，因此只x在时前面的匹配上了
代码如下：

[学习](https://leetcode-cn.com/problems/wildcard-matching/solution/c-dong-tai-gui-hua-yu-shuang-zhi-zhen-tan-xin-by-w/)



### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1, false)); dp[0][0] = true;

        // initialize 
        for (int i = 1; i <= m; ++ i){
            if(p[i - 1] == '*' && dp[0][i - 1]) dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];// ismatch, move on
                }else if (p[j - 1] == '*'){
                    bool zero, mul;// '*' act as zero, '*' act as multiple characters
                    zero = dp[i][j - 1];
                    mul = dp[i -1][j];
                    dp[i][j] = zero || mul;
                }
            }
        }

        return dp[n][m];
    }
};

```

### 双指针

自己这样想过，但是想不出来怎么回溯
```
class Solution {
public:
    bool isMatch(string s, string p) {
        string p2;
        for(int i=0;i<p.size();i++){
            if(p[i]=='*'&&p2[p2.size()-1]=='*') continue;
            else p2+=p[i];
        }
        p=p2;
        int i = 0, j = 0, i_star = -1, j_star = -1, m = s.size(), n = p.size();

        while (i < m){
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                ++ i, ++ j;// 指针同时往后自增1，表示匹配
            }else if (j < n && p[j] == '*') {// 记录回溯的位置
                i_star = i;// 记录星号
                j_star = j++;// 并且j移到下一位,准备下个循环s[i]和p[j]的匹配
                             //(也就是匹配0个字符)
            }else if (i_star >= 0) {// 发现字符不匹配且没有星号出现,但是istar>0 
                                   // 说明*匹配的字符数可能出错 回溯
                i = ++ i_star;//i回溯到i_star+1，显然匹配字符的量出错，现在多匹配一个，且自身加一
                j = j_star + 1;//j回溯到j_star+1 重新使用p串*后的部分开始对齐s串i_star
            } else return false;
        }
        //while (j < n && p[j] == '*') ++ j;// 去除多余星号

        return j == n;
    }
};
```
