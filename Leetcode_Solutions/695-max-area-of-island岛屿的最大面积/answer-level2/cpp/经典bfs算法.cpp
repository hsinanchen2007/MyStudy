### 解题思路
在校入门的小白


### 代码

```cpp
class Solution {
public:
    queue<pair<int,int>> q;
    int visited[51][51]={0};
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    //memset(visited,0,sizeof(visited));
    bool check(vector<vector<int>>& grid,int x,int y){
    if(x<0||y<0||x>=grid.size()||y>=grid[x].size()||grid[x][y]==0||visited[x][y]==1)
        return false;
    return true; 
    }
    int bfs(vector<vector<int>>& grid,int x,int y)
    {
    int num=1;
    visited[x][y]=1;
    q.push({x,y});
    while(!q.empty())
    {
        auto n=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1=n.first+dir[i][0];
            int y1=n.second+dir[i][1];
            if(check(grid,x1,y1))
            {
                visited[x1][y1]=1;
                q.push({x1,y1});
                //printf("%d,%d\n",x1,y1);
                num++;
            }
        }
    }
    return num;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max=0;
    
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]==1&&visited[i][j]==0)
            {
                int a =bfs(grid,i,j);
                if(a>max)
                max=a;
            }
        }
    }
    return max;      
    }
};
```