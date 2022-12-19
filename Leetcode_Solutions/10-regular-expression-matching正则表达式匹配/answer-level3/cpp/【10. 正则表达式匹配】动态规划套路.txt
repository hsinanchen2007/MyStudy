## 思路一：递归
### 代码
```c++
class Solution {
public:
    bool isMatch(string s, string p) {        
        return isMatch(s, 0, p, 0);        
    }

    bool isMatch(string& s, int i, string& p, int j) {
        int sLen = s.size(), pLen = p.size();
        if (j == pLen) return i == sLen;
        if (p[j + 1] == '*') {
            if (isMatch(s, i, p, j + 2) || i < sLen && (p[j] == s[i] || p[j] == '.') && isMatch(s, i + 1, p, j)) return true;
        } else if (i < sLen && (p[j] == s[i] || p[j] == '.') && isMatch(s, i + 1, p, j + 1)) {
            return true;
        }
        return false;
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] == '*') {
            return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)));
        } else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};
```

## 思路二：记忆化搜索
### 代码
```c++
class Solution {
public:
    bool isMatch(string s, string p) {        
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return isMatch(s, 0, p, 0, memo);        
    }

    bool isMatch(string& s, int i, string& p, int j, vector<vector<int>>& memo) {
        if (memo[i][j] > -1) return memo[i][j];
        int sLen = s.size(), pLen = p.size();
        if (j == pLen) return memo[i][j] = i == sLen;
        if (p[j + 1] == '*') {
            if (isMatch(s, i, p, j + 2, memo) || i < sLen && (p[j] == s[i] || p[j] == '.') && isMatch(s, i + 1, p, j, memo)) 
                return memo[i][j] = 1;
        } else if (i < sLen && (p[j] == s[i] || p[j] == '.') && isMatch(s, i + 1, p, j + 1, memo)) {
            return memo[i][j] = 1;
        }
        return memo[i][j] = 0;
    }
};
```

## 思路三：动态规划
### 代码
```c++
class Solution {
public:
    bool isMatch(string s, string p) {     
        int sLen = s.size(), pLen = p.size();   
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[sLen][pLen] = true;
        for (int i = sLen; i >= 0; --i) {
            for (int j = pLen - 1; j >= 0; --j) {
                if (p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || i < sLen && (s[i] == p[j] || p[j] == '.') && dp[i + 1][j];
                } else {
                    dp[i][j] = i < sLen && (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];        
    }
};
```


