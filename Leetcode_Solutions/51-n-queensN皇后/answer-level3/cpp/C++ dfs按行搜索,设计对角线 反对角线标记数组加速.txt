```
    int n;//n皇后时
    vector<vector<string>> ans;
    void dfs(int u, auto &g, auto &col,auto &gd, auto &rgd){
        if(u==n){//搜索完毕
            ans.push_back(g);
            return;
        }
        for(int j = 0; j < n; j++){//枚举u行放在j列时
            if(!col[j]&&!gd[j-u+n]&&!rgd[u+j]){//列,对角,反对角不冲突时
                g[u][j] = 'Q';
                col[j] = gd[j-u+n] = rgd[u+j] = 1;
                dfs(u+1,g,col,gd,rgd);
                g[u][j] = '.';//恢复现场
                col[j] = gd[j-u+n] = rgd[u+j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int len) {
        n = len;
        vector<string> g(n,string(n,'.'));//棋盘初始化
        vector<bool> col(n),gd(2*n),rgd(2*n);//列 对角线 反对角线
        dfs(0,g,col,gd,rgd);//从第0行开始搜索
        return ans;
    }
```
