```
    vector<int> dx = {-1,1,0,0},  dy = {0,0,-1,1};//方向数组
    int g[110][110];//图  g[i][j]==1时表示该点无法进入
    int dfs(int x, int y,int& n, int& m){//从该点开始探索 能探索几个新的格子
        if(g[x][y]) return 0;//该点走不通 过程结束返回0
        g[x][y] = 1;//走上该格子 标记为1 表示以后不用再探索这个了
        int res = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            res += dfs(nx,ny,n,m);//累加其它分支能探索的 
        }
        return res;
    }
    int movingCount(int n, int m, int k) {
        for(int i = 0; i < n; i++)//建图
            for(int j = 0; j < m; j++) if(i%10 + i/10 + j%10 + j/10 > k) g[i][j] = 1;//该点无法进入
        return dfs(0,0,n,m);
    }
```
