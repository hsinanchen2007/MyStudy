### 解题思路
动态规划
并且利用了原数组的空间,
要注意边界问题，grid[i-1][j],grid[i][j-1]要考虑超过边界的情况；
因此有else if(i==0 && j!=0)
        grid[i][j] += grid[i][j-1];
     else if(i!=0 && j==0)
        grid[i][j] += grid[i-1][j];
这两种情况；

### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int length = grid.size();//长度，即行数，（处于哪一行）
        int width = grid[0].size();//宽度，即列数，（处于哪一列）
        //int dp[length] = {0};
        //int flag={[1,0],[0,1]};
        //int sum=grid[0][0];
        for(int i =0;i<length;++i){
            for(int j=0;j<width;++j){
                if(i==0 && j==0)
                    continue;
                else if(i==0 && j!=0)
                    grid[i][j] += grid[i][j-1];
                else if(i!=0 && j==0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += max( grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[length-1][width-1];
    }
};
```