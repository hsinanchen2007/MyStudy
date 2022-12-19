### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MaxDistance(int[][] grid) {
        var res = 0;
        var newGrid = new int[grid.Length, grid[0].Length];
        var isOne = true;
        var isZero = true;
        for(var i = 0; i < grid.Length; i++){
            for(var j = 0; j < grid[i].Length; j++){
                if(grid[i][j] == 1){
                    newGrid[i, j] = 0;
                    isZero = false;
                } 
                else {
                    newGrid[i,j] = 100;
                    isOne = false;
                    if(i > 0)
                        newGrid[i,j] = Math.Min(newGrid[i,j],newGrid[i-1,j]+1);
                    if(j > 0) 
                        newGrid[i,j] = Math.Min(newGrid[i,j],newGrid[i,j-1]+1);
                }
            }
        }
        for(var i = grid.Length-1; i >= 0; i--){
            for(var j = grid[i].Length-1; j >= 0; j--){
                if(grid[i][j] == 1){
                    newGrid[i,j] = 0;
                } 
                else {
                    if(i < grid.Length-1)
                        newGrid[i,j] = Math.Min(newGrid[i,j],newGrid[i+1,j]+1);
                    if(j < grid[i].Length-1) 
                        newGrid[i,j] = Math.Min(newGrid[i,j],newGrid[i,j+1]+1);
                }
            }
        }
        if(isOne || isZero)
            return -1;
        for(var i = 0; i < grid.Length; i++){
            for(var j = 0; j < grid[i].Length; j++){
                if(grid[i][j] == 0)
                    res = Math.Max(res,newGrid[i,j]);
            }
        }
        return res;
    }
}

```