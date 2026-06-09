### 解题思路
代码写的比较形象化，就是看看四个方向能不能走，然后在搜索顺序和剪枝上都做了下优化
![image.png](https://pic.leetcode-cn.com/3a3b4e4eb084b22fd2b186012d2ab40a4e5e8526bc2a9e8c178b5d6d80f8b099-image.png)


### 代码

```cpp
class Solution {
public:
    struct position{
        int north=0;
        int south=0;
        int west=0;
        int east=0;
    }position[301][301];
    int vis[301][301];
    int m,n;
    int flag=false;
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){position[i][j].west=1; position[i][j].east=1;}
                else if(grid[i][j]==2){position[i][j].north=1; position[i][j].south=1;}
                else if(grid[i][j]==3){position[i][j].west=1; position[i][j].south=1;}
                else if(grid[i][j]==4){position[i][j].east=1; position[i][j].south=1;}
                else if(grid[i][j]==5){position[i][j].west=1; position[i][j].north=1;}
                else if(grid[i][j]==6){position[i][j].east=1; position[i][j].north=1;}
            }
        }
        dfs(0,0);
        return flag;
    }
    
    void dfs(int i,int j){
        if(i==m-1&&j==n-1){
            flag=true;
            return ;
        }
        //cout<<i<<","<<j<<endl;
        if(position[i][j].east==1&&j+1<=n-1&&vis[i][j+1]==0&&position[i][j+1].west==1){
            //cout<<"东"<<endl;
            vis[i][j+1]=1;
            dfs(i,j+1);
            //vis[i][j+1]=0;
            if(flag==true) return;
        }
        
        if(position[i][j].south==1&&i+1<=m-1&&vis[i+1][j]==0&&position[i+1][j].north==1){
            //cout<<"南"<<endl;
            vis[i+1][j]=1;
            dfs(i+1,j);
            //vis[i+1][j]=0;
            if(flag==true) return;
        }        
        
        if(position[i][j].west==1&&j-1>=0&&vis[i][j-1]==0&&position[i][j-1].east==1){
            //cout<<"西"<<endl;
            vis[i][j-1]=1;
            dfs(i,j-1);
            //vis[i][j-1]=0;
            if(flag==true) return;
        }

        if(position[i][j].north==1&&i-1>=0&&vis[i-1][j]==0&&position[i-1][j].south==1){
            //cout<<"北"<<endl;
            vis[i-1][j]=1;
            dfs(i-1,j);
            //vis[i-1][j]=0;
            if(flag==true) return;
        }
    }
};
```