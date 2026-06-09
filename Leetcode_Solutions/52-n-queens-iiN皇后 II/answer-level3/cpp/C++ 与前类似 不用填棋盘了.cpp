```
    int n,ans;//n皇后 
    void dfs(int u, auto &col,auto &gd, auto &rgd){
        if(u==n){//搜索完毕
            ans++;
            return;
        }
        for(int j = 0; j < n; j++){//枚举u行放在j列时
            if(!col[j]&&!gd[j-u+n]&&!rgd[u+j]){//列,对角,反对角不冲突时
                col[j] = gd[j-u+n] = rgd[u+j] = 1;//占用
                dfs(u+1,col,gd,rgd);
                col[j] = gd[j-u+n] = rgd[u+j] = 0;//恢复现场
            }
        }
    }
    int totalNQueens(int len) {
        n = len;
        vector<bool> col(n),gd(2*n),rgd(2*n);//列 对角线 反对角线
        dfs(0,col,gd,rgd);//从第0行开始搜索
        return ans;
    }
```
