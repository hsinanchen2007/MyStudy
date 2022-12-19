### 解题思路
感觉我的遍历很多，以为方法很差呢。没想到时间只有1-2ms，内存消耗38MB左右，就分享一下我的代码。

一个腐烂的橘子在传染了四周之后，它就不会再进行传染了。所以，传染是否结束的标志就是一分钟之后，有没有新鲜橘子被腐烂。所以我设了一个全局变量，来标记是否有新腐烂的橘子。如果，过了一分钟，没有新鲜橘子被腐烂，那么要么是所有的橘子都已经腐烂，要么剩下的新鲜橘子永远不会被腐烂。最后，在返回结果的时候，遍历判断一下还有没有新鲜的橘子，如果有就返回-1；没有了，就返回记录的分钟数。

我代码的注释还是比较多的，看代码应该可以看懂。

### 代码

```java
class Solution {
    //标记是否有新腐烂的橘子
    private boolean flag = true;
    public int orangesRotting(int[][] grid) {
        //记录过了几分钟
        int num = 0;
        while (flag) {
            flag = false;
            grid = rotting(grid);
            //有新腐烂的橘子，时间才会增加
            if (flag){
                num += 1;
            }
        }
        if (isHavingFresh(grid)){
            return -1;
        }else {
            return num;
        }
    }
    //判断二维数组中是否含有新鲜橘子
    private boolean isHavingFresh(int[][] grid){
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                if (grid[i][j] == 1){
                    return true;
                }
            }
        }
        return false;
    }
    private int[][] rotting(int[][] grid){
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                if (grid[i][j] == 2){
                    //将已经传染过四周的腐烂橘子设成0，可以提高一点效率
                    //我改了之后，感觉没啥提升，改不改看你心情了~
                    //grid[i][j] = 0;
                    //新腐烂的橘子暂时标记为3
                    if (i-1 >= 0 && grid[i-1][j] == 1){
                        grid[i-1][j] = 3;
                    }
                    if (i+1 < grid.length && grid[i+1][j] == 1){
                        grid[i+1][j] = 3;
                    }
                    if (j-1 >= 0 && grid[i][j-1] == 1){
                        grid[i][j-1] = 3;
                    }
                    if (j+1 < grid[i].length && grid[i][j+1] == 1){
                        grid[i][j+1] = 3;
                    }
                }
            }
        }
        //将新腐烂的橘子改成2
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                if (grid[i][j] == 3){
                    grid[i][j] = 2;
                    flag = true;
                }
            }
        }
        return grid;
    }
}
```