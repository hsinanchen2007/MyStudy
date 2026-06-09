# 解题思路
    1、通过定义bool类型判断是否全0或全1，返回-1
    2、分别从左上到右下、从右下到左上进行遍历
    3、如果grid[i][j]为0，则将newGrid的值设置为100**注意，不能用int.MaxValue，会报错**
    4、最后遍历一遍输出结果

# 实现代码
```
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
