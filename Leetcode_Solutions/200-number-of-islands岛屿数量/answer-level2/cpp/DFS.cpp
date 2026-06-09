```C++ []
class Solution {
public:
    int m, n;
    vector<int> di{1, 0, 0, -1};
    vector<int> dj{0, 1, -1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j]== '0')
            return;
        grid[i][j] = '0';
        for(int x = 0; x < 4; x++)
            dfs(grid, i + di[x], j + dj[x]);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(!m) return 0;
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        
        return ans;
    }
};

```
深度优先搜索，很固定的套路。
1.先判断边界，不符合条件的直接跳出
2.访问该点
3.递归访问接下来的点
需要注意的是，这道题和一般的深度搜索不同。
1.访问该点后，不必重置它的状态，因为我们求岛屿数目，不能重复访问。
2.岛屿不是连续的，所以需要遍历每个点