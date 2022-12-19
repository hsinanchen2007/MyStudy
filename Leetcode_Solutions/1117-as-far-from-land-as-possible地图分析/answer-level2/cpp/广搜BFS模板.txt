```
class Solution {
public:
    static constexpr int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> Q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    Q.push({i,j});
            }
        }

        int size=Q.size();
        if(size==0||size==n*n) return -1;
        int step=0;
        while(!Q.empty())
        {
            size=Q.size();
            while(size--)
            {
                pair<int,int>  Point=Q.front();
                Q.pop();
                for(auto d:delta)
                {
                    int x=Point.first+d[0];
                    int y=Point.second+d[1];

                    if(x>=0&&x<=n-1&&y>=0&&y<=n-1&&grid[x][y]==0)
                    {
                        Q.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
            step++;
        }
        return step-1;
    }
};
```
