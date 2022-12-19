### 解题思路
updown用来记录顶底面积，res记录侧面积
如果这个位置方块数目不是0，顶底面积加2；
侧面面积，先加上应该有的面积，然后减去重合部分的面积的2倍
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int updown = 0,res = 0;

        for(int i = 0;i<row;i++){
            int small;

            res += 4*grid[i][0];
            
            if(grid[i][0]!=0)
                updown += 2;
            
            if(i!=0){
                small = grid[i][0]>grid[i-1][0]?grid[i-1][0]:grid[i][0];
                res -= 2*small;
            }

            for(int j=1;j<col;j++){
                if(grid[i][j]!=0){
                    updown += 2;
                }
                
                res += 4*grid[i][j];
                
                if(i == 0){
                    small = grid[i][j]>grid[i][j-1]?grid[i][j-1]:grid[i][j];
                    res -= 2*small;
                }
                else{                    
                    small = grid[i][j]>grid[i][j-1]?grid[i][j-1]:grid[i][j];
                    res -= 2*small;
                    small = grid[i][j]>grid[i-1][j]?grid[i-1][j]:grid[i][j];
                    res -= 2*small;
                }
            }
        }

        return res + updown;
    }
};
```