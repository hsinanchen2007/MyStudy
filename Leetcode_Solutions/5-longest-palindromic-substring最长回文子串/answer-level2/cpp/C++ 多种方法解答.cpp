> 思路描述：最暴力的做法就是把所有的子串都找出来

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return s;
        string result(1, s[0]);
        for(int i = 2; i <= s.size(); i ++){
            for(int j = 0; j < s.size() - i + 1; j ++){
                string s1 = s.substr(j, i), s2 = s1;
                reverse(s1.begin(), s1.end());
                if(s1 == s2){
                    result = s2;
                    break;
                }
            }
        }
        return result;
    }
};
//写法2
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return s;
        string result(1, s[0]);
        for(int i = 0; i < s.size() - 1; i ++){
            for(int j = i + 1; j < s.size(); j ++){
                string s1 = s.substr(i, j - i + 1);
                string s2 = s1;
                reverse(s1.begin(), s1.end());
                if(s1 == s2 && s2.size() > result.size()){
                    result = s2;
                }
            }
        }
        return result;
    }
};
```

> 但是暴力求解好像过不了，那么采用动态规划的做法，

$我们给出 P(i,j)的定义如下：P(i,j) = \begin{cases} \text{true,} &\quad\text{如果子串} S_i \dots S_j \text{是回文子串}\\ \text{false,} &\quad\text{其它情况} \end{cases}$

因此$P(i,j)=(P(i+1,j-1) and S_i == S_j)$

这产生了一个直观的动态规划解法，我们首先初始化一字母和二字母的回文，然后找到所有三字母回文，并依此类推…

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        string result(1, s[0]);
        vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 1; i <= s.size(); i ++){
            for(int j = 0; j < s.size() - i + 1; j ++){
                if(i == 1) dp[j][j + i - 1] = true;
                else if(i == 2) dp[j][j + i - 1] = (s[j] == s[j + i - 1]);
                else if(dp[j + 1][j + i - 2] && s[j] == s[j + i - 1])
                    dp[j][j + i - 1] = true;
                if(dp[j][j + i - 1] && i > result.size()){
                    result = s.substr(j, i);
                }
            }
        }
        return result;
    }
};
```

> 中心扩展算法
>
> 中心扩散法怎么去找回文串？
> 从每一个位置出发，向两边扩散即可。遇到不是回文的时候结束。举个例子，str=acdbbdaa 我们需要寻找从第一个 `b`（位置为 3）
>
> 出发最长回文串为多少。怎么寻找？
>
> 首先往左寻找与当期位置相同的字符，直到遇到不相等为止。
> 	  然后往右寻找与当期位置相同的字符，直到遇到不相等为止。
>
> 其中要注意aa的中心为空，aba的中心为b

```C++
class Solution {
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return s;
        string result(1, s[0]);
        int len = 0;
        for(int i = 0; i < s.size() - 1; i ++){
            int newLen1 = expandAroundCenter(s, i, i + 1);
            int newLen2 = expandAroundCenter(s, i, i);
            int maxLen = max(newLen1, newLen2);
            if(maxLen > len){
                len = maxLen;
                result = s.substr(i - (maxLen-1)/2, maxLen);
            }
        }
        return result;
    }
};
```

