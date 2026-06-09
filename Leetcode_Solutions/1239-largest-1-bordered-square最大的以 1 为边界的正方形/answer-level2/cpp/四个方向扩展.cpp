1.  求矩阵中的每个点(x,y),向上下左右四个方向能够延展的连续1的最长距离。
2.  对矩阵中的每个点，向下延展的最大距离的点，依次递减，满足能够构成矩形的最长边长。
3.  求出最长的边长即可。

```
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        int edgs[100][100][4];
        
        /*left*/
        for(int i = 0;i < r; ++i){
            int left = 0;
            for(int j = 0;j < c; ++j){
                if(grid[i][j] == 1){
                    left++;
                }else{
                    left = 0;
                }
                edgs[i][j][0] = left;
            }
        }
        /*right*/
        for(int i = 0;i < r; ++i){
            int right = 0;
            for(int j = c-1;j >= 0; --j){
                if(grid[i][j] == 1){
                    right++;
                }else{
                    right = 0;
                }
                edgs[i][j][1] = right;
            }
        }
        /*up*/
        for(int j = 0;j < c; ++j){
            int up = 0;
            for(int i = 0;i < r; ++i){
                if(grid[i][j] == 1){
                    up++;
                }else{
                    up = 0;
                }
                edgs[i][j][2] = up;
            }
        }
        /*down*/
        for(int j = 0;j < c; ++j){
            int down = 0;
            for(int i = r-1;i >= 0; --i){
                if(grid[i][j] == 1){
                    down++;
                }else{
                    down = 0;
                }
                edgs[i][j][3] = down;
            }
        }
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                for(int k = edgs[i][j][3] - 1; k >= 0 ; --k){
                    if((i+k) < r && (j+k) < c){
                        if(edgs[i][j][1] > k && 
                           edgs[i+k][j+k][2] > k && 
                           edgs[i+k][j+k][0] > k){
                            ans = max(ans,(k+1)*(k+1));
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
```