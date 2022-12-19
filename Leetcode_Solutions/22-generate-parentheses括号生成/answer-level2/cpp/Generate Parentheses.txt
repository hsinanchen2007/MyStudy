### 解题思路
Generate Parentheses

### 代码

```cpp
class Solution {
public:
    void generate(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size()==2*n) 
        {
            ans.push_back(cur);
            return;
        }
        if (open<n) 
        {
            cur.push_back('(');
            generate(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close<open) 
        {
            cur.push_back(')');
            generate(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        generate(res, current, 0, 0, n);
        return res;
    }
};
```