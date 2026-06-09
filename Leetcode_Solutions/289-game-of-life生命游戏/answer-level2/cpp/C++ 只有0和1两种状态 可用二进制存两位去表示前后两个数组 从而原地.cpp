```
    //死->死 00 死->活 10 活->死 01 活->活 11  低位表示初始状态 高位表示改变后的状态
    void gameOfLife(vector<vector<int>>& a) {
        int dx[] = {-1,1,0,0,-1,-1,1,1},dy[] = {0,0,-1,1,1,-1,1,-1};
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(a[nx][ny]&1) cnt++;//表示该位置前一状态为活的
                }
                if(a[i][j]&1){//对于活细胞
                    if(cnt<2||cnt>3) a[i][j] = 1;//死亡 活->死 01 
                    else a[i][j] = 3;//存活 活->活 11
                }
                else if(cnt==3) a[i][j] = 2;//死->活 10
            }
        }
        for(int i = 0; i < n; i++){//取得最终状态
            for(int j = 0; j < m; j++) a[i][j] = (a[i][j]>>1)&1;
        }
    }
```

