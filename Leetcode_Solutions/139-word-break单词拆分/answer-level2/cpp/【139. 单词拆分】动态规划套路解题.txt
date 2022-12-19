## 思路一：暴力（超时）
尝试每一个可能的前缀。
### 代码
时间复杂度：O(n^n)
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        return helper(s, uset, 0);
    }
    bool helper(string s, unordered_set<string> &uset, int start) {
        if (start == s.size()) {
            return true;
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            if (uset.count(s.substr(start, end - start)) > 0 && helper(s, uset, end)) {
                return true;
            }
        }
        return false;
    }
};
```

## 思路二：记忆化搜索
### 代码
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return helper(s, uset, 0, memo);
    }
    bool helper(string s, unordered_set<string> &uset, int start, vector<int> &memo) {
        if (start == s.size()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            if (uset.count(s.substr(start, end - start)) > 0 && helper(s, uset, end, memo)) {     
                memo[start] = 1;
                return memo[start];
            }
        }
        memo[start] = 0;
        return memo[start];
    }
};
```

## 思路三：动态规划
### 代码
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && uset.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```

