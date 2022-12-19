```
class Solution {
public:
    vector<int> dx = {-1,1,0,0}, dy = {0,0,-1,1};//上 下 左 右
    void dfs(vector<vector<char>>& g, int x, int y){//从i,j开始访问 将所有连通的1变为0
        g[x][y]='0';
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx>=0&&nx<g.size()&&ny>=0&&ny<g[0].size()&&g[nx][ny]=='1') dfs(g,nx,ny);//合法时访问
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int ans = 0;
        for(int i = 0; i < g.size(); i++)
            for(int j = 0; j < g[0].size(); j++) if(g[i][j] == '1') ans++,dfs(g,i,j);
        return ans;
    }
};
```
