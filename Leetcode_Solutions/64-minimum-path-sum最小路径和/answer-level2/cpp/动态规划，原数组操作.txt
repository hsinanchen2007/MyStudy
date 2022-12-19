``` C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;        
        for(int m=0;m<grid.size();m++)
        {
            for(int n=0;n<grid[m].size();n++)
            {
                
                int left=n-1>=0?grid[m][n-1]:0;
                int up=m-1>=0?grid[m-1][n]:0;
                if(m==0)
                    grid[m][n]+=left;
                else if(n==0)
                    grid[m][n]+=up;
                else
                    grid[m][n]+=min(left,up);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
```