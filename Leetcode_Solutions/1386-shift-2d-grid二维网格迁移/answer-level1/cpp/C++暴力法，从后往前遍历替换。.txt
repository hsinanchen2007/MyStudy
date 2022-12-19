

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int raws = grid.size();  
        int cols = grid[0].size(); 
        int  temptail;
        
        while( k > 0) {
            temptail = grid[raws - 1][cols - 1];
            
            for (int i = raws - 1; i >= 0; i--) {
                for (int k = cols - 1; k >= 0; k--) {
                    if ((k == cols - 1) && (i == raws - 1)) {
                        continue;
                    }

                    if (k == cols - 1) {
                        grid[i + 1][0] = grid[i][k];
                    } else {
                        grid[i][k + 1] = grid[i][k];
                    }                                                              
                }
            }

            grid[0][0] = temptail;   
            k--;
        }

        return grid;

    }
};