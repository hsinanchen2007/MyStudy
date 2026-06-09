class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int k = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] < 0)
                {
                    k += 1; 
                }
            }
        }
        return k;
    }
};