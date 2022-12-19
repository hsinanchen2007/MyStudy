遍历每个点，进行rows*cols次dfs，已经搜过的点使用cache记录长度，直接返回值即可
返回int的dfs一直不是很理解，只会这么写了
```
class Solution {
public:
vector<vector<int>> cache;
vector<vector<int>> used;
int rows, cols;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int dfs(vector<vector<int>> &matrix, int x, int y)
{
    int res = 1;
    if (cache[x][y] > 0)
        return cache[x][y];
    used[x][y] = true;
    for (int k = 0; k < 4; ++k)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !used[nx][ny] && matrix[nx][ny] > matrix[x][y])
        {
            res = max(res, dfs(matrix, nx, ny) + 1);
        }
    }
    used[x][y] = false;
    cache[x][y] = res;
    return res;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    rows = matrix.size();
    if (rows == 0)
        return 0;
    cols = matrix[0].size();
    if (cols == 0)
        return 0;
    cache = vector<vector<int>>(rows, vector<int>(cols, 0));
    used = vector<vector<int>>(rows, vector<int>(cols, 0));
    int res = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            res = max(res, dfs(matrix, i, j));
    }
    return res;
}
};
```

