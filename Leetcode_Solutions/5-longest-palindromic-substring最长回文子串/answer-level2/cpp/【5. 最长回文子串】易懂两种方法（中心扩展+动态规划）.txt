## 思路一：中心扩展
考虑最长回文串为奇数和偶数两种情况。
### 代码
```c++
class Solution {
    int pos, maxLen;
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) {
            return s;
        }
        for (int i = 0; i < size; ++i) {
            extend(s, i, i);//假设最长为奇数，尝试尽可能向两边扩展
            extend(s, i, i+1);//假设最长为偶数，尝试尽可能向两边扩展
        }
        return s.substr(pos, maxLen);
    }
private:
    void extend(const string &s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L, R++;
        }
        if (R - L - 1 > maxLen) {
            maxLen = R - L -1;
            pos = L + 1;
        }
    }
};
```
### 不使用全局变量
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) {
            return s;
        }
        int maxLen = 1, start = 0;
        for (int i = 0; i < size; ++i) {
            int len1 = extend(s, i, i);
            int len2 = extend(s, i, i+1);
            if (max(len1, len2) > maxLen) {
                maxLen = max(len1, len2);
                start = len1 > len2 ? (i - (len1 - 1) / 2) : (i - (len2 - 1) / 2);
            }            
        }
        return s.substr(start, maxLen);
    }
private:
    int extend(const string &s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L, R++;
        }
        return R - L - 1;
    }
};
```

## 思路二：动态规划
dp[i][j]：表示范围i...j的字符串是否是回文串。
从头遍历各个字符：
1. 首先单个字符本身是回文串
2. 从最左边到当前字符依次判断是否是回文串
   - 如果当前字符和左边字符相等，即s[i] == s[j]，则判断去掉头尾的字符是否是回文串，如果两个字符相邻或前一个状态dp[j+1][i-1] = true，则是回文串，然后判断是否最长。
   - 如果不相等，则不是回文串。
### 代码
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) {
            return s;
        }
        bool dp[size][size];        
        int maxLen = 1, start = 0;
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true; //单个字符本身
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j] && (i - j == 1 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        start = j;
                    }
                } else {
                    dp[j][i] = false;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
```
