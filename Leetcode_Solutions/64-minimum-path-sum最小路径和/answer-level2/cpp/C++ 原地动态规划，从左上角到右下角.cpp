特殊情况尽可能清晰一些。

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col= grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0) continue;
                //左增加量,第一列特殊
                int left_add = j==0? INT_MAX:grid[i][j-1];
                //上增加量，第一行特殊
                int up_add = i==0? INT_MAX:grid[i-1][j];

                grid[i][j] += min(left_add,up_add); 
                
            }
        }
        return grid[row-1][col-1];
    }
};
```
