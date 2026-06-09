### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void isReached(vector<vector<int> >& grid, int x, int y, int step, int &count){
        /*check the success condition*/
        if (step<=0){
            if ( (x>0 && grid[x-1][y] == 2) || 
                 (x<grid.size()-1 && grid[x+1][y] == 2) ||
                 (y>0 && grid[x][y-1] == 2) || 
                 (y<grid[x].size()-1 && grid[x][y+1] == 2) ){
                count++;
            }
            return;
        }
        /*set current point -1 then traval around the point*/
        int old = grid[x][y];
        grid[x][y] = -1;        
        if (x>0 && grid[x-1][y]==0) {
            isReached(grid, x-1, y, step-1, count);
        }
        if (y>0 && grid[x][y-1]==0) {
            isReached(grid, x, y-1, step-1, count);
        }
        if (x<grid.size()-1 && grid[x+1][y]==0) {
            isReached(grid, x+1, y, step-1, count);
        }        
        if (y<grid[0].size()-1 && grid[x][y+1]==0) {
            isReached(grid, x, y+1, step-1, count);
        }
        grid[x][y] = old;
    }
    int uniquePathsIII(vector<vector<int> >& grid) {
        int count = 0;
        int x= 0, y = 0,step = 0;
        /*find the start point and count the 0 points*/
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if (grid[i][j]==0)
                    step++;
                if (grid[i][j]==1){
                    x = i;
                    y = j;
                }
            }
        }
        isReached(grid, x, y, step, count);
        return count;
    }
};
```