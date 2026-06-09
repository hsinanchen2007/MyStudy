
这道题和[542. 01矩阵](https://leetcode-cn.com/problems/01-matrix/)比较像，感觉就是把0和1换了一下，返回值变成最大值。整体思路还是类似的，就是先把所有的1压入队列，然后逐层遍历，找到距离1最远的0。
```c++
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        bx = grid.size();
        by = grid[0].size();
        
        queue<Pair> que;
        vector<vector<bool>> vis(bx, vector<bool>(by, false));
        int ones, zeros;
        ones = zeros = 0;
        
        for(int i = 0;i < bx; ++i){
            for(int j = 0;j < by; ++j){
                if(grid[i][j] == 1){
                    que.push(Pair(i,j));
                    vis[i][j] = true;
                    ones++;
                }else zeros++;
            }
        }
        if(ones == bx*by || zeros == bx*by) return -1;
        int ans = 0;
        while(que.size()){
            Pair p = que.front();
            que.pop();
            for(int i = 0;i < 4; ++i){
                int nx = p.first + dir[i][0];
                int ny = p.second + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || vis[nx][ny]) continue;
                que.push(Pair(nx, ny));
                grid[nx][ny] = grid[p.first][p.second] + 1;
                vis[nx][ny] = true;
                if(ans < grid[nx][ny]) ans = grid[nx][ny];
            }
        }
        return ans - 1;
    }
private:
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int bx, by;
    using Pair = pair<int, int>;
};
```