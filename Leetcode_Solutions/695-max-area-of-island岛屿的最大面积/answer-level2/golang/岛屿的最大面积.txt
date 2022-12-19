### 解题思路
简单易懂暴力递归

### 代码
cpp
```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int LandSize = 0;
        int res = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1){
                    LandSize = 0;
                    help(i,j,LandSize,grid);
                    res = max(res,LandSize);
                }
            }
        }
        return res;
    }
    void help(int i,int j,int& size,vector<vector<int>>&grid){
        if(i<0||i>=grid.size() || j<0||j>=grid[0].size() || grid[i][j]!=1)
            return;
        
        size++;
        grid[i][j] = 2;                 //防止重复
        help(i+1,j,size,grid);
        help(i-1,j,size,grid);
        help(i,j+1,size,grid);
        help(i,j-1,size,grid);
    }
};
```

go
```go
func maxAreaOfIsland(grid [][]int) int {
    row := len(grid);
    col := len(grid[0]);
    LandSize,res := 0,0
    
    for i:=0;i<row;i++ {
        for j := 0;j<col;j++ {
            if grid[i][j] == 1 {
                LandSize = 0
                help(grid,i,j,&LandSize)
                res = max(res,LandSize)
            }
        }
    }
    return res;
}

func help(grid [][]int,i int,j int,size *int) {
    if i<0||i>=len(grid) || j<0||j>=len(grid[0]) || grid[i][j] != 1 {
        return
    }
    
    *size++;
    grid[i][j] = 2;
    help(grid,i+1,j,size);
    help(grid,i-1,j,size);
    help(grid,i,j+1,size);
    help(grid,i,j-1,size);
}
func max(i int,j int) int {
    if i>j{
        return i
    }
    return j
}
```
