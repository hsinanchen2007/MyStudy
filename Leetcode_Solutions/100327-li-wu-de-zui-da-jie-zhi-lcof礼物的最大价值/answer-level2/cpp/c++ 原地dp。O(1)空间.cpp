```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int colLen=grid[0].size();
        int rowLen=grid.size();
        for(int col=colLen-1;col>=0;--col){
            for(int row=rowLen-1;row>=0;--row){
                int down=0,right=0;
                if(row+1<rowLen)down=grid[row+1][col];
                if(col+1<colLen)right=grid[row][col+1];
                grid[row][col]+=max(down,right);
            }
        }
        return grid[0][0];
    }
};
```
