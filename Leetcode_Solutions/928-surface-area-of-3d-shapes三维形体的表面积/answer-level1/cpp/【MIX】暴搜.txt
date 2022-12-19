### 解题思路
直接暴搜

### 代码

```java []
class Solution {
    public int surfaceArea(int[][] grid) {
        if(grid==null || grid.length==0 || grid[0]==null || grid[0].length==0)
            return 0;

        this.R = grid.length;
        this.C = grid[0].length;

        int S = 0;

        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(grid[i][j] > 0){
                    S += 4*grid[i][j]+2;

                    for(int []d: dirs){
                        int ni = i+d[0];
                        int nj = j+d[1];

                        if(inArea(ni, nj) && grid[ni][nj] > 0){
                            S-=Math.min(grid[i][j], grid[ni][nj]);
                        }
                    }
                }
            }
        }
        return S;

    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

    private int[][]dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private int R, C;
```
```python []
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if grid == None or len(grid)==0:
            return 0

        R, C, S = len(grid), len(grid[0]), 0
        
        def inArea(x, y):
            return 0<=x and x<R and 0<=y and y<C

        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]

        for i in range(R):
            for j in range(C):
                if grid[i][j] > 0:
                    S += 4*grid[i][j]+2
                    for d in dirs:
                        ni = i+d[0]
                        nj = j+d[1]
                        if inArea(ni, nj) and grid[ni][nj]>0:
                            S-=min(grid[i][j], grid[ni][nj])

        return S
```
```c++ []
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        R = grid.size();
        if(R == 0)
            return 0;
        C = grid[0].size();
        if(C == 0)
            return 0;

        int S = 0;
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j){
                if(grid[i][j] != 0){
                    S += (grid[i][j]*4+2);
                    for(auto& d: dirs){
                        int ni = i+d[0];
                        int nj = j+d[1];
                        if(inArea(ni, nj) && grid[ni][nj]>0){
                            S-=min(grid[i][j], grid[ni][nj]);
                        }
                    }
                }
            }
        return S;
    }

private:
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int R, C;
};
```