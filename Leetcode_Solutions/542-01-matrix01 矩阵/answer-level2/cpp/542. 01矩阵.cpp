
首先把所有的0压入队列，然后逐层遍历并更新，即首先遍历更新距离为1的，再遍历更新距离为2的，以此类推。

```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        bx = matrix.size();
        by = matrix[0].size();
        
        vector<vector<int>> ans(bx, vector<int>(by, 0));
        vector<vector<bool>> vis(bx, vector<bool>(by, false));
        queue<pair<int, int>> que;
        
        //把所有0压入队列
        for(int i = 0;i < bx; ++i){
            for(int j = 0;j < by; ++j){
                if(!matrix[i][j]){
                    que.push(make_pair(i,j));
                }
            }
        }
        
        //一层一层地遍历
        while(que.size()){
            auto now = que.front();
            que.pop();
            
            for(int i = 0;i < 4;i++){
                int nx = now.first + dir[i][0];
                int ny = now.second + dir[i][1];
                
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || vis[nx][ny] || !matrix[nx][ny]) continue;
                
                vis[nx][ny] = true;
                que.push(make_pair(nx, ny));
                ans[nx][ny] = ans[now.first][now.second] + 1;
            }
        }
        return ans;
    }
private:
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int bx, by;
};
```