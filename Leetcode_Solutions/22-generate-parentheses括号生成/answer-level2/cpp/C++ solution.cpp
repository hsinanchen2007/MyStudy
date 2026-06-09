### 解题思路
深搜

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, "", 0, 0);
        return v;
    }
private:
    vector<string> v;
    void dfs(int n, string s, int left, int right) {
        if (n == left && n == right) {
            v.push_back(s);
            return;
        }
        if (left < n) {
            dfs(n, s + '(', left + 1, right);
        }
        if (right < left && right < n) {
            dfs(n, s + ')', left, right + 1);
        }
    }
};
```