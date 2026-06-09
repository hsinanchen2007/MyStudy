### BFS
```
typedef pair<int,int>pq;
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};
class Solution {
public://BFS先放入队列的数据会优先的处理，所以这样会好一点的。。。
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pq>que;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    que.push({i,j});
                }
            }
        }
        if(que.empty()||que.size()==m*n)return -1;
        int res=0;
        while(!que.empty()){
            auto v=que.front();
            que.pop();
            int ans=grid[v.first][v.second];
            for(int i=0;i<4;i++){//遍历四个方向
                int x=dx[i]+v.first;
                int y=dy[i]+v.second;
                if(x<0||y<0||x>=m||y>=n)continue;
                if(grid[x][y]!=0)continue;
                grid[x][y]=ans+1;
                res=max(res,grid[x][y]);
                que.push({x,y});
            }
        }
        return res-1;
    }
};
```

