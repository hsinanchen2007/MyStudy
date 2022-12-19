### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;

        map<pair<int,int>, set<pair<int,int> > > record;

        int totalArea=0;
        int overlapArea=0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] > 0)
                {
                    totalArea+=(6+4*(grid[i][j]-1));
                    if(i-1>=0 && record[{i,j}].count({i-1,j})==0)
                    {
                        overlapArea+=min(grid[i][j],grid[i-1][j])*2;
                        record[{i,j}].insert({i-1,j});
                        record[{i-1,j}].insert({i,j});
                    }
                    if(j+1<n && record[{i,j}].count({i,j+1})==0)
                    {
                        overlapArea+=min(grid[i][j],grid[i][j+1])*2;
                        record[{i,j}].insert({i,j+1});
                        record[{i,j+1}].insert({i,j});
                    }
                    if(i+1<m && record[{i,j}].count({i+1,j})==0)
                    {
                        overlapArea+=min(grid[i][j],grid[i+1][j])*2;
                        record[{i,j}].insert({i+1,j});
                        record[{i+1,j}].insert({i,j});
                    }
                    if(j-1>=0 && record[{i,j}].count({i,j-1})==0)
                    {
                        overlapArea+=min(grid[i][j],grid[i][j-1])*2;
                        record[{i,j}].insert({i,j-1});
                        record[{i,j-1}].insert({i,j});
                    }
                }
            }
        }

        return totalArea-overlapArea;
    }
};
```