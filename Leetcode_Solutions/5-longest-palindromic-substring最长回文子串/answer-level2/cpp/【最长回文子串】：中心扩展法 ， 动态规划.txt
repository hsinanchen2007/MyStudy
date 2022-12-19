# 中心扩展法

#### 使用中心扩展法需要理解以下几点：
1. 对于一个回文串，它有一个中心，该中心可以为一个字符，也可以只是两个字符之间的间隙。
2. 找到中心后向左右同时进行扩展，并且左右两边的字符应该对应相等。

对于该题我们可以从字符串的左边第一个字符开始，首先以第一个字符作为中心，求出对应回文串的长度len1，再以它右边的间隙为中心，求出对应回文串的长度len2，以此类推知道遍历完整个数组为止，便可得到最长的回文子串了。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        int maxLen = 1, start = 0;
        for (int i = 0; i < s.length(); i++) {
            int len = lenOfPalindrome(s, i);
            if (len > maxLen) {
                maxLen = len;
                start = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
    int lenOfPalindrome(string& s, int c) {
        int l, r;
        int len1, len2;
        for (l = c, r = c; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
        len1 = r - l - 1;
        for (l = c, r = c+1; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
        len2 = r - l - 1;
        return max(len1, len2);
    }
};
```


# 动态规划

#### 使用动态规划解决此问题的步骤：
1. 定义一个二维数组`bool dp[len-1][len-1]`来记录遍历字符串所得的状态，dp[l][r]为true表示从l到r的子串为回文串，false表示不是回文串
2. 初始化二维数组，单个字符为回文串，所以定义`dp[i][i] = true`
3. 找到状态转移方程，`dp[l][r] = (s[r]==s[l] && (r-l==1 || dp[l+1][r-1])) ? true : false`

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0)
            return s;
        bool dp[len][len];
        int start = 0, end = 0;
        for (int i = 0; i <len; i++)
            dp[i][i] = true;
        for (int r = 1; r < len; r++)
            for (int l = 0; l < r; l++)
                if (s[r]==s[l] && (r-l==1 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    if (r-l > end-start) {
                        start = l; end = r;
                    }
                    continue;
                }else
                    dp[l][r] = false;
        return s.substr(start, end-start+1);
    }
};
```

### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。


至此，您已经掌握了使用中心扩展法和动态规划解决此题，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)