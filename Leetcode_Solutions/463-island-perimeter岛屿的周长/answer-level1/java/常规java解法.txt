### 解题思路
也就是遍历一下数组，每次遍历开头默认为4个周长都可以算进去，然后该位置周围每有一个“1”,就将4 - 1，最后每次都加上count，就可以了

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int sum = 0;
        for(int i = 0; i < grid.length; i ++){
            for(int j = 0; j < grid[0].length; j++){
                int count = 4;
                if(grid[i][j] == 1){
                    if(i - 1 >= 0){
                        if( grid[i - 1][j] == 1)
                            count--;
                    }
                    if(i + 1 < grid.length){
                        if(grid[i+1][j] == 1)
                            count--;
                    }
                    if(j - 1 >= 0){
                        if(grid[i][j - 1] == 1)
                            count--;
                    }
                    if(j + 1 < grid[0].length) {
                        if(grid[i][j + 1] == 1){
                            count--;
                        }
                    }
                    sum += count;
                }
            }
        }
        return sum;
    }
}
```