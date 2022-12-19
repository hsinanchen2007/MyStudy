### 解题思路
由于是从左上角到右下角，只需要向下和向右就可以保证到达，而不需要向上和向左
![image.png](https://pic.leetcode-cn.com/3c330945b01a7aceaa6a3c454bc5e4e5a8106cf2e4bd6f2be434d5e55d889867-image.png)

### 代码

```cpp
class Solution {
public:
    inline int sum(int num)
    {
        int ans = 0;
        while(num)
        {
            ans += num % 10;
            num /= 10;
        } 
        return ans;
    }
    int dfs(int m, int n, int r, int c, int k, vector<vector<int>>& visited)
    {
        if(r >= m || c >= n || sum(r) + sum(c) > k || visited[r][c]) return 0;
        visited[r][c] = 1;
        return 1 + dfs(m, n, r + 1, c, k, visited) + dfs(m, n, r, c + 1, k, visited);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector(n, 0));
        return dfs(m, n, 0, 0, k, visited);
    }
};
```