 1034. 边框着色

关键点：

1、深度优先搜索DFS

2、4个方向搜索 上、右、下、左

3、走过的路要标识成特殊数值，本题选择的0

4、染色时先用临时色-1替代color，以为color可能和起始色相同，导致搜索成环

![image.png](https://pic.leetcode-cn.com/8120fe786ee054f28171610cfdc3e0a389d80103c0b613b95a5bad2c6758b534-image.png)


5、边界判断：

     1）在网格的边界上（第一行/列或最后一行/列）的所有正方形。  

     if(x == 0 || y == 0 || x == xNum-1 || y == yNum - 1){
         // 边界直接染色
         grid[y][x] = color;
      }          

   2) 上下左右的边界，既不和起始颜色相同 !=tmpColor，也不是走过的路径（!=0）,也不是已经染过色的!= color
   3) 满足上面条件的，证明它和边界相连，可以染成color
      if(grid[y - 1][x] != tmpColor && grid[y - 1][x] != 0 && grid[y - 1][x] != color) flag = true;
      if(grid[y + 1][x] != tmpColor && grid[y + 1][x] != 0 && grid[y + 1][x] != color) flag = true;            
      if(grid[y][x - 1] != tmpColor && grid[y][x - 1] != 0 && grid[y][x - 1] != color) flag = true;            
      if(grid[y][x + 1] != tmpColor && grid[y][x + 1] != 0 && grid[y][x + 1] != color) flag = true;

      if(flag == true){
         grid[y][x] = color;
      }else{
         grid[y][x] = 0;
      }
