#### 最初理解错误，我一开始是对每一个位置进行DFS访问的，之后发现有些位置被挡住，那么需要通过挡住位置进入下一个位置的做法就不行了，因为挡住是过不去的，即使有些位置是符合题目要求的。
#### 所以这个题目可以理解成求解一个连通图的最多符合条件的结点的个数是多少个。。。
#### 使用DFS一次操作即可完成。。。
```
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
class Solution {
public:
    int count(int x,int y){
        int num=0;
        while(x){
            num+=x%10;
            x=x/10;
        }
        while(y){
            num+=y%10;
            y=y/10;
        }
        return num;
    }
    void dfs(int i,int j,int m,int n,int k,vector<vector<int>>& vis,int &res){
        vis[i][j]=1;
        res++;
        cout<<res<<endl;
        for(int t=0;t<4;t++){
            int x=dx[t]+i;
            int y=dy[t]+j;
            if(x>=0&&y>=0&&x<m&&y<n&&vis[x][y]==0&&count(x,y)<=k){
                //cout<<x<<" "<<y<<" "<<count(x,y)<<" "<<k<<endl;
                dfs(x,y,m,n,k,vis,res);
            }
        }
    }
    int movingCount(int m, int n, int k) {
        int res=0;
        vector<vector<int>>vis(m+100,vector<int>(n+100,0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(vis[i][j]==0&&count(i,j)<=k){
        //             dfs(i,j,m,n,k,vis,res);
        //         }
        //     }
        // }
        dfs(0,0,m,n,k,vis,res);
        return res;
    }
};
```
