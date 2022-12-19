### 解题思路
四周的计算外表面积，向右向下计算高度差

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int res = 0;
        if(N == 1)
            return 4*grid[0][0]+2;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] !=0 )
                    res += 2;
                if(i==0 || i==N-1)
                    res += grid[i][j];
                if(j==0 || j==N-1)
                    res += grid[i][j];
                if(i+1<N)
                    res += abs(grid[i][j] - grid[i+1][j]);
                if(j+1<N)
                    res += abs(grid[i][j] - grid[i][j+1]);
            }
        }
        return res;
    }
};
```