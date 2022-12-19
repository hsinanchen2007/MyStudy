```
#define  u p.first 
#define v p.second
class Solution {
public:
    int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
    int maxDistance(vector<vector<int>>& grid) {
        //多源bfs
        int n=grid.size();
        int cnt=0;
        int dis[n][n];
        queue<pair<int,int>>q;
        memset(dis,0,sizeof(dis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j])cnt++;
                else{
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int a=u+dx[i],b=v+dy[i];
                if(a>=0&&a<n&&b>=0&&b<n&&grid[a][b]!=-1){
                    cnt--;
                    q.push({a,b});
                    grid[a][b]=-1;
                    dis[a][b]=dis[u][v]+1;
                    if(!cnt){
                        return dis[a][b];
                    }
                }
            }
        }
        return -1;
    }
};
```
