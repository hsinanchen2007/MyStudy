

```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int n=grid.size(),m=grid[0].size();
        int t0=0,t1=0,t2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push(make_pair(i,j));
                    t2+=1;
                }
                else if(grid[i][j]==1) t1+=1;
                else t0+=1;
            }
        }
        if(t1==0) return 0;
        if(t2==0&&t1!=0) return -1;
        int count=-1,len,l,r;
        while(!que.empty()){
            count+=1;
            len=que.size();
            for(int i=0;i<len;i++){
                l=que.front().first;
                r=que.front().second;
                que.pop();
                if(r-1>=0&&grid[l][r-1]==1){
                    que.push(make_pair(l,r-1));
                    grid[l][r-1]=2;
                    t1-=1;
                }
                if(l-1>=0&&grid[l-1][r]==1){
                    que.push(make_pair(l-1,r));
                    grid[l-1][r]=2;
                    t1-=1;
                }  
                if(r+1<=m-1&&grid[l][r+1]==1){
                    que.push(make_pair(l,r+1));
                    grid[l][r+1]=2;
                    t1-=1;
                }  
                if(l+1<=n-1&&grid[l+1][r]==1){
                    que.push(make_pair(l+1,r));
                    grid[l+1][r]=2;
                    t1-=1;
                }                                            
            }
        }
        if(t1>0) return -1;
        else return count;
    }
};
```
