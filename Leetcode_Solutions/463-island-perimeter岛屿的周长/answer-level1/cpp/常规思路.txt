```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //先在网格外围添一圈湖
        int w_n = grid[0].size(); //获取宽度
        int h_n = grid.size(); //获取高度
        vector<int> temp;
        int c = 4;
        int C = 0;
        for(int i = 0; i < h_n; ++i)
        {
            //每一行首尾添加一个湖
            grid[i].insert(grid[i].begin(), 0); 
            grid[i].insert(grid[i].end(), 0);
        }
        for(int j = 0; j < w_n + 2; ++j)
            temp.push_back(0);
        
        //首尾添加一行湖
        grid.insert(grid.begin(), temp);
        grid.insert(grid.end(), temp);
    
        for(int i = 1; i <= h_n; ++i)
        {
            for(int j = 1; j <= w_n; ++j)
            {
                if(grid[i][j] != 0)
                {
                    if(grid[i][j - 1] != 0)
                        c--;
                    if(grid[i][j + 1] != 0)
                        c--;
                    if(grid[i - 1][j] != 0)
                        c--;
                    if(grid[i + 1][j] != 0)
                        c--;
                    C += c;
                }
                c = 4;
                
            }
        }
        
        return C;
    }
};
```
