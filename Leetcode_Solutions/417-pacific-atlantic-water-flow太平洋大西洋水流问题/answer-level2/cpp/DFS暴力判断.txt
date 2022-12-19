### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return res;
        mat = matrix;
        n = matrix.size();
        m = matrix[0].size();
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                cnt1 = 0, cnt2 = 0;
                vector<int> v;
                memset(vis, false, sizeof(vis));
                DFS(i, j);
                if(cnt1 > 0 && cnt2 > 0)
                    res.push_back(vector<int>{i, j});
            }
        }
        return res;
    }
    void DFS(int x, int y)
    {
        if(y == -1 || x == -1)
        {
            cnt1++;
            return ;
        }
        if(y == m || x == n)
        {
            cnt2++;
            return ;
        }
        for(int i = 0 ; i < 4 ; ++i)
        {
            int newX = x + nextX[i];
            int newY = y + nextY[i];
            if(newX == -1 || newY == -1 || newX == n || newY == m)
                DFS(newX, newY);
            else if(!vis[newX][newY] && mat[newX][newY] <= mat[x][y])
            {
                vis[newX][newY] = true;
                DFS(newX, newY);
            }
        }
    }
private:
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0, 0, 1, -1};
    bool vis[160][160] = {false};
    int cnt1 = 0, cnt2 = 0;
    int n, m;
    vector<vector<int>> mat;
    vector<vector<int>> res;
};
```