1. 首先我们建立一个模型，先给矩阵按0到n*m-1编号，然后连边建图，点u能指向v的要求是v在u的四个方向内且v对应的值大于u
2. 然后问题就简化成在一张有向图中求最长距离
3. 直接dfs发现最后三个点超时，于是加个记忆化就可以了
```代码如下 []
class Solution {
public:
    int h[100000],to[100000],next[100000],d[100000],f[100000],cnt,ans=1;
    bool vis[100000];
    int mx[4] = {-1,1,0,0};
    int my[4] = {0,0,-1,1};
    void add(int u,int v){
        to[++cnt] = v; next[cnt] = h[u]; h[u] = cnt;
    }
    bool valid(int x,int y,int n,int m){
        return (x >= 0 && x < n && y >= 0 && y <m);
    }
    int dfs(int u){
        if(h[u] == 0 || vis[u]) return f[u];
        for(int e = h[u]; e; e = next[e]){
            dfs(to[e]);
            vis[to[e]] = true;
            f[u] = max(f[u],f[to[e]] + 1);
            ans = max(ans,f[u]);
        }
        return f[u];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(vis,0,sizeof vis);
        if(matrix.empty()) return 0;
        for(int i = 0; i < matrix.size()*matrix[0].size(); i++) f[i] = 1;
        for(int x= 0; x < matrix.size(); x++)
            for(int y = 0; y < matrix[0].size(); y++){
                for(int i = 0; i < 4; i++){
                    int nx = x + mx[i];
                    int ny = y + my[i];
                    if(valid(nx,ny,matrix.size(),matrix[0].size())){
                        if(matrix[nx][ny] > matrix[x][y])
                            add(x*matrix[0].size()+y,nx*matrix[0].size()+ny),
                            d[nx*matrix[0].size()+ny]++;
                    }
                }
            }
        for(int i = 0; i < matrix.size()*matrix[0].size(); i++){
            if(d[i] == 0 && h[i] != 0){
                dfs(i);
                vis[i] = true;
            }
        }
        return ans;
    }
};
