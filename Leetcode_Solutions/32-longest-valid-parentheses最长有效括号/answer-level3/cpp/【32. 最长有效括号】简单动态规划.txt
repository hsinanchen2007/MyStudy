## 思路一：动态规划
设一维dp[i]表，表示以i位置结尾的最长有效括号。
- 如果遇到左括号，则为 0。
- 如果遇到右括号，则可能存在以s[i]结尾的最长有效括号子串，dp[i-1]表示以s[i-1]结尾的最长有效子串，所以，如果位置i - dp[i-1] - 1位置为左括号，则能与s[i]配对。比如"(()())"，假设遍历到最后一个字符右括号，dp[i-1] = 4，i - dp[i-1] - 1位置为左括号，此时dp[i]至少为dp[i-1] + 2。在位置 i - dp[i-1] - 1的前一个位置还可能存在一个有效括号子串，所以需要加上dp[i-dp[i-1]-2]。
### 代码
```c++
class Solution {
public:
    int longestValidParentheses(string s) {        
        if (s.empty()) {
            return 0;
        }
        int size = s.size(); 
        int res = 0;
        vector<int> dp(size);        
        for (int i = 1; i < size; ++i) {
            if (s[i] == ')') {
                int pre = i - dp[i-1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (pre > 0) {
                        dp[i] += dp[pre-1];
                    }
                    res = max(res, dp[i]);
                }                
            } 
        }
        return res;
    }
};
```
#### 简化代码
```c++
class Solution {
public:
    int longestValidParentheses(string s) {        
        if (s.empty()) {
            return 0;
        }
        int size = s.size(); 
        int res = 0;
        vector<int> dp(size);        
        for (int i = 1; i < size; ++i) {
            if (s[i] == ')') {
                int pre = i - dp[i-1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i-1] + 2 + (pre > 0 ? dp[pre-1] : 0);
                    res = max(res, dp[i]);
                }                
            } 
        }
        return res;
    }
};
```


