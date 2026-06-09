直接dfs ，染色就行了
```
class Solution {
public:
    int maxx;
    int now;
    vector< vector<int>>grid;
    void oil(int x,int y,int row,int col){
        if(x >=row || x<0 || y >=col || y < 0){
            return ;
        }
        if(grid[x][y] == 1){
            now++;
            // 因为传递的是引用，所以不能修改原来的数组。
            grid[x][y] = 0;
            oil(x+1,y,row,col);
            oil(x,y+1,row,col);
            oil(x-1,y,row,col);
            oil(x,y-1,row,col);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // O n的算法，直接dfs染色法。
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        this->grid = grid;
        maxx = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(this->grid[i][j] == 1){
                    now = 0;
                    oil(i,j,row,col);
                    if(now > maxx) maxx = now;
                }
            }
        }
        return maxx;
    }
};
```
