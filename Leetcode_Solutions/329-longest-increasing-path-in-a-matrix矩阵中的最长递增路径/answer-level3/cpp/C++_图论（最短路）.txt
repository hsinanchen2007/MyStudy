# 思路：
刚开始做的时候有一个很直接的想法，以图的每个点为起点，分别计算以其作为起点的长度，取最大值即可。    
实现也很简单，每个点做dfs即可找出其为起点的最长递增路径。代码如下：
```
class Solution {
    vector<vector<int>> inPath;
    bool isOK(int x,int y){
        int n=(int)inPath.size();
        int m=(int)inPath[0].size();
        return x>=0&&x<n&&y>=0&&y<m&&inPath[x][y]==0;
    }
    int dfs(int x,int y,int level,vector<vector<int>>&matrix){
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        inPath[x][y]=1;
        int ans=level;
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0];
            int yy=y+dir[i][1];
            if(isOK(xx,yy)&&matrix[x][y]<matrix[xx][yy]){
                ans=max(ans,dfs(xx,yy,level+1,matrix));
            }
        }
        inPath[x][y]=0;
        return ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int n=(int)matrix.size();
        int m=(int)matrix[0].size();
        inPath.resize(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ans=max(ans,dfs(i,j,1,matrix));
        }
        return ans;
    }
};
```
然而上述代码不出意料的TLE了。想了一下，首先没必要对每个点dfs，因为需要dfs的起点必然是局部（上下左右中）最小的点。    
其次也不需要dfs暴搜。我们不妨将满足u<v的点连边建图，这样可以得到一个DAG（有向无环）森林。将森林中的所有DAG跑最长路    
就是结果了。求最长路可以转为最短路，将边权为1的最长路取-1来求最短路即可。这里我用的是SPFA。代码如下：
```
class Solution {
    vector<vector<int>> g;
    queue<int> q;
    int n,m;
    bool isOK(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
    vector<int> dist;
    int SPFA(){
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<(int)g[u].size();i++){
                int v=g[u][i];
                if(dist[u]-1<dist[v]){
                    dist[v]=dist[u]-1;
                    q.push(v);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*m;i++) ans=min(ans,dist[i]);
        return 1-ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=(int)matrix.size();
        if(n==0) return 0;
        m=(int)matrix[0].size();
        g.resize(n*m);
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=i*m+j;
                bool isStart=true;
                for(int k=0;k<4;k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(isOK(x,y)){
                        if(matrix[x][y]>matrix[i][j]) g[i*m+j].push_back(x*m+y);
                        else if(matrix[x][y]<matrix[i][j]) isStart=false;
                    }
                }
                if(isStart) q.push(i*m+j);
            }
        }
        dist.resize(n*m,0);
        return SPFA();
    }
};
```