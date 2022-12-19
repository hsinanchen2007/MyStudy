我先说下我对于DFS的理解，我觉得应该在到达边界之后不应该结束DFS，因为其上下左右可能还有连通分量，应该继续去走。本题不需要多余的数组去存储我们更改的位置，直接使用原始的数组即可。不过我们需要记录我们走过的位置,走过的位置我们就不走了。
我简单说下我DFS的思路，首先判断是否越界，越界返回-1，（1代表该位置的值不是连通分量的值，也就是该位置上下左右的连通分量为连通分量边界，-1为其他）。之后先判断该位置的值是否被更改过，如果被更改过就可以直接返回-1，如果不是在这一分支，说明该值要么可能没走过要么可能走过了但该值不等于连通分量中的值，假如该值不为连通分量的值，那么我们就要返回1，不管其是否走过，之后不处于这个分支，就只能是没走过的连通分量支或走过的连通分支但没有被更改,只要是走过的我们就应该返回-1。核心思路就是留下我们没走过的连通分量，之后去该位置的上下左右，之后去判断该位置是否为第一/最后一行或者第一/最后一列，如果是直接可以更改该位置的值为color，如果不是的话就去判断该位置是否为边界（上下左右是否有一个为1）。结束判断。
讲一下为什么是这个逻辑，假如我们先判断该值不等于oldColor，那么该值可能之前等于，但后来更改了就变成了不等于oldColor，这样返回1就是错误的。之后还有第二个分支为什么要在前面，不管该值我们遍历没遍历过，只要原本就不等于oldColor，我们就会返回1，他旁边的连通分量就是连通分量的边界。
```java
class Solution {
    int[][]grid;
    boolean[][]flag;
    int rows;
    int columns;
    int oldColor;
    int color;
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        this.color = color;
        this.grid = grid;
        if(grid==null||grid.length==0)
             return grid;
        oldColor = grid[r0][c0];
        rows = grid.length;
        columns = grid[0].length;
        flag = new boolean[rows][columns];
        dfs(r0,c0);
        return grid;
    }
    public int dfs(int i,int j)
    {   
        //不能先判断flag[i][j]再判断grid[i][j]!=oldColor,
        //这样有一个bug(比如第二行的第四个1，是连通分量的边界（上面是2），但可能这个2已经走过了，这样先判断flag[i]就会跳出去了)
        //比如21221
        //    11111
        //    22212
        //    12212
        //    21112
        //r0=1，c0=4，也就是oldColor=1。
        if(i<0||i>=rows||j<0||j>=columns)
            return -1;
         //防止该值被更改过了值
         if(flag[i][j]&&grid[i][j]==color)
            return -1;
        //不管遍历没遍历过只要该值本来就不是连通分量的值，就返回1。
        else if(grid[i][j]!=oldColor){
            return 1;
        }//如果该遍历过了，不再继续遍历了。
        else if(flag[i][j])
            return -1;
       
            
        flag[i][j] = true;
        //边界(要涂色)
        int d = dfs(i+1,j);
        int u = dfs(i-1,j);
        int r = dfs(i,j+1);
        int l = dfs(i,j-1);
        if(i==0||j==0||i==rows-1||j==columns-1)
        {
            grid[i][j] = color;
        }
        else if(d==1||u==1||r==1||l==1)
        { 
            grid[i][j] = color;
        }      
         return -1;
    }
}
```

