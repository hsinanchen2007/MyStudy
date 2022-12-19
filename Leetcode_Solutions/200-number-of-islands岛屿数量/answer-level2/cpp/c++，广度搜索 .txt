### 解题思路
此处撰写解题思路
![截图.PNG](https://pic.leetcode-cn.com/19735aac7227904a3091a281d86eacd56c6529280088b73d14e3ecb2070fff67-%E6%88%AA%E5%9B%BE.PNG)

### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int res = 0;
        for(int i  = 0 ; i < row; i++)
        {
            for(int j  = 0; j < col; j++)
            {
                if(visited[i][j] == false && grid[i][j] == '1')
                {
                    bfs(grid, visited, i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char>>& grid, vector<vector<bool>> &visited,int row, int col){
        queue<pair<int, int>> q;
        char c='1';
        q.push({row,col});
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int x = val.first;
            int y = val.second;
            visited[val.first][val.second] = true;
            if(x > 0 && grid[x-1][y] == c && visited[x-1][y] == false) {q.push({x-1,y});visited[x-1][y] = true;}
            if(x < grid.size()-1&&grid[x+1][y] == c && visited[x+1][y] == false) {q.push({x+1,y});visited[x+1][y] = true;}
            if(y > 0 &&grid[x][y-1] == c && visited[x][y-1] == false) {q.push({x,y-1});visited[x][y-1] = true;}
            if(y < grid[0].size()-1 &&grid[x][y+1] == c && visited[x][y+1] == false) {q.push({x,y+1});visited[x][y+1] = true;}
        }
    }
};
```