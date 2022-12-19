### 解题思路
首先别管那么多，既然规定了必须跟着管道走，咱就跟着管道走，比如说当前管道可以连接右，那么我们就判断他左连的那个管道是否可以连接左(这样才能两个管道才想通)，如果连接咋就过去，dfs操作。其他方向同理。

但是双100%是我没想到的，交的人太少了？
![MULLVTGKR7DNUBZLY1IFE4Q.png](https://pic.leetcode-cn.com/0d3488c9b2473033f6deb78670f177caca8fee68e031fbf61622212ac2e0f463-MULLVTGKR7DNUBZLY1IFE4Q.png)

### 代码

```java
class Solution {
    boolean b =false;
    int lx,ly;
    public boolean hasValidPath(int[][] grid) {
        lx = grid.length;
        ly = grid[0].length;
        fun(0,0,grid);
        return b;
    }
    public void fun(int x,int y,int[][] grid){
        if(x == lx-1 && y == ly-1){
            b = true;
        }
        int t = grid[x][y];
        grid[x][y] = 0;
        switch(t){
            case 1:
                if(y-1 >= 0){
                    if(grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6){
                        fun(x,y-1,grid);
                    }
                }
                if(y+1 < ly){
                    if(grid[x][y+1] == 3 || grid[x][y+1] == 3 || grid[x][y+1] == 5){
                        fun(x,y+1,grid);
                    }
                }
            case 2:
                if(x-1 >= 0){
                    if(grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4){
                        fun(x-1,y,grid);
                    }
                }
                if(x+1 < lx){
                    if(grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6){
                        fun(x+1,y,grid);
                    }
                }
            case 3:
                if(y-1 >= 0){
                    if(grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6){
                        fun(x,y-1,grid);
                    }
                }
                if(x+1 < lx){
                    if(grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6){
                        fun(x+1,y,grid);
                    }
                }
            case 4:
                if(y+1 < ly){
                    if(grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5){
                        fun(x,y+1,grid);
                    }
                } 
                if(x+1 < lx){
                    if(grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6){
                        fun(x+1,y,grid);
                    }
                }
            case 5:
                if(y-1 >= 0){
                    if(grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6){
                        fun(x,y-1,grid);
                    }
                }
                if(x-1 >= 0){
                    if(grid[x-1][y] == 2 || grid[x-1][y] ==  3 || grid[x-1][y] == 4){
                        fun(x-1,y,grid);
                    }
                } 
            case 6:
                if(y+1 < ly){
                    if(grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5){
                        fun(x,y+1,grid);
                    }
                }
                if(x-1 >= 0){
                    if(grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4){
                        fun(x-1,y,grid);
                    }
                }
        }
    }
}
```