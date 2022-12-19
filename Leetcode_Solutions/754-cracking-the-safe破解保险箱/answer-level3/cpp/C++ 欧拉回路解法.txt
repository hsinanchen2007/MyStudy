### 代码

```cpp
class Solution {
public:
    int visited[10001] = {0};
    int P = 0;
    void dfs(int k, int i, string& res) {
        i -= i / P * P;
        i *= 10;
        for (int j = 0; j < k; ++j) {
            int t = i + j;
            if (!visited[t]) {
                visited[t] = 1;
                dfs(k, t, res);
                res += j + '0';
            }
        }
    }
    string crackSafe(int n, int k) {
        P = pow(10, n - 1);
        visited[0] = 1;
        string res;
        dfs(k, 0, res);
        res.append(n, '0');
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6992dcc4df5e448c97b64673186210b2652730a719649a635f92995c295b069b-image.png)
