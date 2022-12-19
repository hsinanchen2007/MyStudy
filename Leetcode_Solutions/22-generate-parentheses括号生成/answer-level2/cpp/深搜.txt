### 解题思路
深搜即可

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, n, "", ans);
        return ans;
    }
    // left为已经使用的左括号个数
    // right表示还能使用多少个右括号
    void dfs(int left, int right, int n, string s, vector<string>& ans) {
        // 若左括号全部使用并且右括号都匹配了
        if(left == n && right == 0) {
            ans.push_back(s);
            return ;
        }
        if(left < n) dfs(left + 1, right + 1, n, s + '(', ans);
        if(right != 0) dfs(left, right - 1, n, s + ')', ans);
    }
};
```