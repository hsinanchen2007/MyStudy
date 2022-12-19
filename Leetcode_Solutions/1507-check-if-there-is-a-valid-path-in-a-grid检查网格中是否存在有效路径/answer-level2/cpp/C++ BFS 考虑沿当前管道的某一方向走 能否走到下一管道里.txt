```
    bool hasValidPath(vector<vector<int>>& g) {
        int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};//方向数组 上下 左右
        vector<vector<int>> dir(7,vector<int>(2));
        dir[1] = {2,3},dir[2] = {0,1},dir[3] = {2,1};
        dir[4] = {3,1},dir[5] = {2,0},dir[6] = {3,0};//每种管子代表的两种方向 用方向数组的下标代替
        int n = g.size(), m = g[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> st(n,vector<bool>(m));//访问标记
        q.push({0,0});//起点开始
        st[0][0] = true;
        while(q.size()){
            auto v = q.front();
            q.pop();
            int x = v.first, y = v.second;
            if(x==n-1&&y==m-1) return true;
            for(int i = 0; i < 2; i++){//从当前管子开始走
                int j = dir[g[x][y]][i];//当前前进方向
                int nx = x + dx[j], ny = y + dy[j];//下一点位置
                if(nx<0 || nx >= n || ny < 0|| ny >= m || st[nx][ny]) continue;
                int nxd = g[nx][ny];//下一个管子类型
                if(j==0&&(nxd==2||nxd==3||nxd==4)||j==1&&(nxd==2||nxd==5||nxd==6)
                   ||j==2&&(nxd==1||nxd==4||nxd==6)||j==3&&(nxd==1||nxd==3||nxd==5)){//能接上 则可以走过去
                    st[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
```
