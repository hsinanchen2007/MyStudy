解题使用DFS，这个思路比较容易看出来。
难点是怎么判断下一个格子的形状，是否和上一个格子匹配。
观察6种形状，每种形状只有两个方向，一个连接上游，一个连接下游。
把6种形状的方向在定义时直接写出来：
```
    vector<vector<int>>dr = {{0, 0}, {-1, 1}, {0, 1}, {0, 1}, {-1, 0}, {-1, 0}};
    vector<vector<int>>dc = {{1, -1}, {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
```
方向数字只有：0, 1, -1三种；和形状结合起来，匹配的形状满足条件： dr[i] + dr[j] == 0 && dc[i] + dc2[i] == 0。
代码实现比较简单：
    Dfs()深度遍历， 找到终点时修改结果值
    IsOk()判断下一个格子是否越界。
    IsMatch()判断下一个格子是否和当前格子匹配。
    使用visit[r][c], 让Dfs沿着一个方向走到结果（或者无路可走）。
    几个常用的变量，懒得多次传参数，直接作为类成员变量。

```
class Solution {
public:
    vector<vector<int>>dr = {{0, 0}, {-1, 1}, {0, 1}, {0, 1}, {-1, 0}, {-1, 0}};
    vector<vector<int>>dc = {{1, -1}, {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};   
    int R, C; 
    vector<vector<bool>>visit;
    bool ans = false;    
    bool IsOk(int r, int c)
    {
        if(r >= 0 && c >= 0 && r < R && c < C) {
            return true;
        }
        return false;
    }
    bool IsMatch(vector<vector<int>>& grid, int r, int c, int dir, int nr, int nc)
    {        
        for(int i = 0; i < 2; i++) {            
            int num1 = grid[r][c] - 1, num2 = grid[nr][nc] - 1;
            if(dr[num1][dir] + dr[num2][i] == 0 
                && dc[num1][dir] + dc[num2][i] == 0) {                
                return true;
            }             
        }
        return false;
    }
    void Dfs(vector<vector<int>>& grid, int r, int c)
    {        
        for(int i = 0; i < 2; i++) {
            int num = grid[r][c] - 1;
            int nr = r + dr[num][i];
            int nc = c + dc[num][i];
            if(IsOk(nr, nc) && visit[nr][nc] == false && IsMatch(grid, r, c, i, nr, nc)) {
                if(nr == R-1 && nc == C-1) {
                    ans = true;
                    return;
                }
                visit[nr][nc] = true; 
                Dfs(grid, nr, nc);
            }
        }        
    }
    bool hasValidPath(vector<vector<int>>& grid) 
    {        
        if(grid.size() == 1 && grid[0].size() == 1) return true;
        R = grid.size();
        C = grid[0].size();
        visit.resize(R, vector<bool>(C, false));
        visit[0][0] = true;      
        Dfs(grid, 0, 0);
        return ans;
    } 
};
```
