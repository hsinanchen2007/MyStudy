### 解题思路
遍历每个橘子

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int res=0;
        vector<int> dx={-1,0,0,1};
        vector<int> dy={0,1,-1,0};
        queue<pair<int,int>> rot;
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                if(grid[i][j]==2)
                    rot.push({i,j});
        while(!rot.empty())
        {
            int vol=rot.size();
            for(int i=0;i<vol;i++)
            {
                 pair<int,int> fir=rot.front();
                 rot.pop();
                   for(int j=0;j<4;++j)
                {
                    int x=fir.first+dx[j],y=fir.second+dy[j];
                    if(x>=0&&x<row&&y>=0&&y<col&&grid[x][y]==1)//判断是否存在新鲜橘子
                    {
                        grid[x][y]=2;
                        rot.push({x,y});
                    }
                }     
            }
            if(!rot.empty())
            res++;
        }
         for(int i=0;i<row;++i)//检查是否还有新鲜橘子
            for(int j=0;j<col;++j)
                if(grid[i][j]==1)
                    return -1;
        return res;        
    }
};
```