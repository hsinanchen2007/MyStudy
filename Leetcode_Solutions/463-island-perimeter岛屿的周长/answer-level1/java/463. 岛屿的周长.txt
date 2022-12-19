/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/17
 * 
 * 解题思路: 模拟法 看一块土地旁边有没有水 一个边有水的+1 靠近边界+1
 * 
 */

```
public int islandPerimeter(int[][] grid) {
    int l = 0;
    for(int i = 0;i < grid.length;i++){
        for(int j = 0;j < grid[i].length;j++){
            if(grid[i][j] == 1){
                if((i - 1 < 0) || (i-1 >= 0 && grid[i-1][j] == 0)){
                    l++; //上
                }

                if((i + 1 >= grid.length) || (i+1 < grid.length && grid[i+1][j] == 0)){
                    l++; //下
                }

                if((j - 1 < 0) || (j-1 >= 0 && grid[i][j - 1] == 0)){
                    l++; //左
                }

                if((j+1 >= grid[i].length) || (j+1 < grid[i].length && grid[i][j + 1] == 0)){
                    l++; //右
                }
            }
        }
    }
    return l;
}
```