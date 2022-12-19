区域生长法思路活用
```
class Solution {
    vector<pair<int,int>> findOnes(vector<vector<int>>& grid)
    {
        vector<pair<int,int>> locs;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    locs.push_back(make_pair(i,j));
            }
        return locs;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        //quick judge
        int sum=0;
        for(int i=0;i<grid.size();i++)
        {
            sum+=accumulate(grid[i].begin(), grid[i].end(), 0);
        }
        if(sum==0||sum==grid.size()*grid[0].size())
            return -1;
        //area growth
        int row=grid.size();
        int col=grid[0].size();
        int loops=-1;
        //direction array
        //4-neighbour
        int irow[4] {0,0,-1,1};
        int jcol[4] {-1,1,0,0};
        //
        vector<pair<int,int>> lands=findOnes(grid);
        vector<pair<int,int>> newLands;
        while(lands.size()!=0)
        {
            loops++;
            newLands.clear();
            for(auto [i,j]:lands)
                for(int k=0;k<4;k++)
                {
                    if(i+irow[k]>=0&&i+irow[k]<row&&j+jcol[k]>=0&&j+jcol[k]<col)
                        if(grid[i+irow[k]][j+jcol[k]]==0)
                        {
                            grid[i+irow[k]][j+jcol[k]]=1;
                            newLands.push_back(make_pair(i+irow[k],j+jcol[k]));
                        }
                }
            lands=newLands;
        }
        return loops;

    }
};
```
