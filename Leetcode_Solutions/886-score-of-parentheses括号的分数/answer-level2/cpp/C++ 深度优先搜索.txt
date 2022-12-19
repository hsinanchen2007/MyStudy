```cpp
class Solution {
public:
    int dfs(const string& s, int l, int r) {
        if (l >= r) return 0;
        int res = 0;
        int c = 0;
        int u = l;
        int v = l;
        while (v <= r) {
            c += s[v] == '(' ? 1 : -1;
            if (c == 0) {
                res += (v - u > 1) ? (2 * dfs(s, u + 1,  v - 1)) : 1;
                u = v + 1;
            }
            ++v;
        }
        return res;
    }
    int scoreOfParentheses(string S) {
        return dfs(S, 0, S.size() - 1);
    }
};
```

![image.png](https://pic.leetcode-cn.com/b8bad33cdf9769216f3fae7f9a8f6ab93ec3fdd58a0e167c74e1b799d630cd76-image.png)
