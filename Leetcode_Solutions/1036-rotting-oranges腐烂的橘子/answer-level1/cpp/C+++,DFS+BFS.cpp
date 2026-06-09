解法一：DFS
```
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
class Solution {
public:
    //这里需要对普通的DFS进行一定的处理，即DFS进化版本。。。
    void dfs(vector<vector<int>>& grid,int i,int j,int res){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())return ;
        if(grid[i][j]!=1&&grid[i][j]<res)return ;//预防不符合条件的再次访问。。。
        grid[i][j]=res;
        res++;

        for(int k=0;k<4;k++){
            int x=dx[k]+i,y=dy[k]+j;
            dfs(grid,x,y,res);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,2);//很好解决我没法解决的问题。。。
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
                else{
                    cnt=max(cnt,grid[i][j]);
                    //cout<<cnt<<endl;
                }
            }
        }
        if(cnt==0)return 0;
        return cnt-2;


    }
};
```
解法二：BFS
```
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){//初始化
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        int res=0;
        while(!que.empty()){
            int k=que.size();
            bool flag=false;
            for(int i=0;i<k;i++){
                pair<int,int>q=que.front();
                que.pop();
                int f1=q.first,f2=q.second;
                for(int j=0;j<4;j++){
                    int x=dx[j]+f1,y=dy[j]+f2;
                    if(x>=0&&y>=0&&x<m&&y<n&&grid[x][y]==1){
                        flag=true;
                        grid[x][y]=2;
                        que.push({x,y});
                    }
                }
            }
            if(flag)res++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return res;
    }
};
```

