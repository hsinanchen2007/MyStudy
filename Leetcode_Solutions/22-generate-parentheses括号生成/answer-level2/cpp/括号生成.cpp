### 解题思路
参考[官方题解](https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/)

### 代码

```cpp
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();     //回溯
        }
        if (close < open) {     //当右括号的个数小于左括号时（即此时添加在cur中的右括号比左括号少时）才可以添加右括号，否则不行
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();     //回溯
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
```