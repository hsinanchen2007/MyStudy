### 解题思路
我，新手，太菜了。一个简单题，我想了半天的时间才想出来。虽然也没专注的想，不过专注想这题我怕是会疯。可能大神有很好的方法，我只能想到循环、标记、判断。总觉得循环多了不好，可是我也想不到别的。不说废话了，我说下我的大致思路吧。
腐烂橘子传染的是跟它相邻的新鲜橘子，所以传染的时候要判断被传染的橘子是不是新鲜橘子。如果是，则先改变其值为3，表示是新腐烂的。如果直接改为2，会导致其旁边的橘子也直接被传染，而不是一分钟后再被传染。等所有新感染的橘子都确定了之后，再让它们统一改为2。
flag为true，表示有新腐烂的橘子，则可以再次进行腐烂传染，并将表示时间的标识num加一。而当flag为false时，表示没有新腐烂的橘子，也就意味着这时所有的橘子都已腐烂，或者腐烂的橘子和剩余的新鲜橘子之间有空格，无法进行腐烂传染。如果是所有橘子都已腐烂则返回num，如果还有橘子未腐烂，则这些橘子永远不会腐烂，就返回-1。

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
            //只有当有新鲜橘子腐烂时，时间才会增加
            if (flag){
                num+=1;
            }
        }
        //腐烂传染结束时，如果仍有新鲜橘子，则表示无法让所有橘子都腐烂
        if (isHavingFresh(grid)){
            return -1;
        }else {
            return num;
        }
    }
    //判断二维数组中是否含有新鲜橘子
    private void isHavingFresh(int[][] grid){
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                if (grid[i][j] == 1){
                    return true;
                }
            }
        }
        return false;
    }
    //腐烂传染
    private int[][] rotting(int[][] grid){
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                //新腐烂的橘子暂时标记为3
                if (grid[i][j] == 2){
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