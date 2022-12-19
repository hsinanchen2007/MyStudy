### 解题思路
1.令dp[i][j]表示S[i]到S[j]表示的子串是否为回文串，是为1，否则为0.
2.根据S[i]是否等于S[j]有两种情况：
a.S[i] == S[j]时，如果dp[i+1][j-1]=1，则dp[i][j]必然等于1.
b.S[i] != S[j]时，则dp[i][j]必然等于0，即不是回文子串。
3.边界条件是：dp[i][i]=1,dp[i][i+1]=(S[i]==s[i+1])
思考一下：i和j该如何遍历才能让dp[i][j]根据已知的值算出来呢？

按照子串的长度和子串的起始位置做遍历，这样j就等于i-1+len

4.遍历时记录最长子串的长度和起始位置即可。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
    //动态规划
    //1.字符串长度小于2时单独处理
    if (s.empty()) 
    {
        return "";
    }
    int len = s.size();
    if (len == 1)
    {
        return s;
    }
       
    int longest = 1;
    int start = 0;

    vector<vector<int> > dp(len,vector<int>(len));

    //初始条件  dp[i][i] = 1和dp[i][i + 1] = 1当s[i] == s[i + 1]时
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if(i < len - 1)//下标 i+1 < len  ==> i < len-1
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;//记录起始位置
                longest = 2;
            }
        }
    }

    //外层循环以子串长度作为遍历条件，取值范围从3---len
    for (int l = 3; l <= len; l++)//遍历子串长度
    {
        for (int i = 0; i + l - 1 < len; i++)//遍历子串的起始点
        {
            int j = l + i - 1;//终点
            if (s[i] == s[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                start = i;
                longest = l;//记录当前的最长长度
            }
        }
    }
    return s.substr(start,longest);
    }
};
```