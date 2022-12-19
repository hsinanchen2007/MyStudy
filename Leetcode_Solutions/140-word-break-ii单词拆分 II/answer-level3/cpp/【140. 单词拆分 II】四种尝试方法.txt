## 思路一：暴力（超时）
### 代码
```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());        
        return helper(s, wordSet, 0);
    }
    vector<string> helper(string s, unordered_set<string> &wordSet, int start) {
        if (start == s.size()) {
            return {""};
        }
        vector<string> res;
        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.count(s.substr(start, end - start)) > 0) {
                vector<string> tmp = helper(s, wordSet, end);
                for (auto str : tmp) {
                    res.push_back(s.substr(start, end - start) + (str.empty() ? "" : " ") + str);
                }
            }
        }
        return res;
    }
};
```

## 思路二：记忆化搜索
### 代码
```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  
        unordered_map<int, vector<string>> memo;
        return helper(s, wordSet, 0, memo);
    }
    vector<string> helper(string s, unordered_set<string> &wordSet, int start, unordered_map<int, vector<string>> &memo) {
        if (memo.count(start) > 0) {
            return memo[start];
        }
        if (start == s.size()) {
            return {""};
        }
        vector<string> res;
        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.count(s.substr(start, end - start)) > 0) {
                vector<string> tmp = helper(s, wordSet, end, memo);
                for (auto str : tmp) {
                    res.push_back(s.substr(start, end - start) + (str.empty() ? "" : " ") + str);
                }
            }
        }
        memo[start] = res;
        return res;
    }
};
```

## 思路三：动态规划（超时）
官方题解超时？？？
### 代码
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  
        vector<vector<string>> dp(s.size() + 1);
        vector<string> res;
        res.push_back("");
        dp[0] = res;
        for (int i = 1; i <= s.size(); ++i) {
            vector<string> tmp;
            for (int j = 0; j < i; ++j) {
                if (dp[j].size() > 0 && wordSet.count(s.substr(j, i - j)) > 0) {
                    for (string str : dp[j]) {
                        tmp.push_back(str + (str.empty() ? "" : " ") + s.substr(j, i - j));
                    }
                }
            }
            dp[i] = tmp;
        }
        return dp[s.size()];
    }
};
```

## 思路四：递归
### 代码
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> umap;
        return helper(s, wordDict, umap);
    }
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>> &umap) {
        if (umap.count(s) > 0) {
            return umap[s];
        }
        if (s.empty()) {
            return {""};
        }
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            vector<string> rem = helper(s.substr(word.size()), wordDict, umap);
            for (auto str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return umap[s] = res;
    }
};
```
