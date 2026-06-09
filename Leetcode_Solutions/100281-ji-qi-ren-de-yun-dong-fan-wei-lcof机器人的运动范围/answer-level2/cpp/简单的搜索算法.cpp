刚开始觉得很简单，把所有符合的坐标找出来就可以了，提交的时候发现结果比我运行的少，又仔细看了一遍题目，发现很多坐标虽然符合要求，但是机器人无法走到，于是重新写了一遍，完美运行！

```
class Solution
{
public:
    vector<vector<int>> vis;
    int movingCount(int m, int n, int k)
    {
        vis.assign(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, k);
    }
    int dfs(int x, int y, int m, int n, int k)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == 1 || 
            x/10 + x%10 + y/10 + y%10 > k)
            return 0;
        vis[x][y] = 1;
        //只需要判断右和下两个方向
        return dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k) + 1;
    }
};
```
