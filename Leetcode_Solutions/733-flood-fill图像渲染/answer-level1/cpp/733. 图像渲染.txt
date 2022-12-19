
这道题BFS和DFS都可以做，算是一道比较基础的模板题。

#### 方法1 DFS

```c++ []
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bx = image.size();
        by = image[0].size();
        vector<vector<bool>> vis(bx, vector<bool>(by, false));
        dfs(image,sr,sc,newColor,vis);
        return image;
    }
private:
    int dir[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};
    int bx, by;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& vis){
        if(vis[sr][sc]) return;
        vis[sr][sc] = true;
        for(int i = 0;i < 4; ++i){
            int nx = sr + dir[i][0];
            int ny = sc + dir[i][1];
            if(nx < 0 || nx >= bx || ny < 0 || ny >= by || image[sr][sc] != image[nx][ny])
                continue;
            dfs(image, nx, ny, newColor,vis);
        }
        image[sr][sc] = newColor;
        return ;
    }
};
```

#### 方法2 BFS

```c++ []
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bx = image.size();
        by = image[0].size();
        vector<vector<bool>> vis(bx, vector<bool>(by, false));
        bfs(image, sr, sc, newColor, vis);
        return image;
    }
private:
    int dir[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};
    int bx, by;
    
    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& vis){
        queue<pair<int,int>> que;
        que.push(make_pair(sr, sc));
        int oldColor = image[sr][sc];
        while(que.size()){
            auto p = que.front();
            que.pop();
            if(vis[p.first][p.second]) continue;
            image[p.first][p.second] = newColor;
            vis[p.first][p.second] = true;
            for(int i = 0;i < 4;i++){
                int nx = p.first + dir[i][0];
                int ny = p.second + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || oldColor != image[nx][ny])
                    continue;
                que.push(make_pair(nx,ny));
            }
        }
        return ;
    }
};
```