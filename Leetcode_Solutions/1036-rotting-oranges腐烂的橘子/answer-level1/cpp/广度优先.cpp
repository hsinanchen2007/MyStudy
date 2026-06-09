```c++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,res=0;
        int m=grid.size();
        if(m==0)return 0;
        int n=grid[0].size();
        deque<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)++fresh;
                else if(grid[i][j]==2)
                    q.push_back({i,j});
            }
        }
        if(fresh==0)return 0;
        while(!q.empty()){
            ++res;
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop_front();
                if(x!=0){
                    if(grid[x-1][y]==1){
                        q.push_back({x-1,y});
                        grid[x-1][y]=2;
                        --fresh;
                        flag=true;
                    }
                }
                if(y!=n-1){
                    if(grid[x][y+1]==1){
                        q.push_back({x,y+1});
                        --fresh;
                        flag=true;
                        grid[x][y+1]=2;
                    }
                }
                if(x!=m-1){
                    if(grid[x+1][y]==1){
                        q.push_back({x+1,y});
                        --fresh;
                        flag=true;
                        grid[x+1][y]=2;
                    }
                }
                if(y!=0){
                    if(grid[x][y-1]==1){
                        q.push_back({x,y-1});
                        --fresh;
                        flag=true;
                        grid[x][y-1]=2;
                    }
                }
            }
            if(fresh==0)return res;
        }
        return -1;
        
    }
};
```