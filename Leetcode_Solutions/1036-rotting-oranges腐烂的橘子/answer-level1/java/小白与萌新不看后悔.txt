### 解题思路
这题要是简单题，我觉得我没必要在刷题了！真的。。。。。。

挂了一次，然后用时3ms通过，我tm暴力算法时间复杂度有o(n^3)，给我说击败了71.83%，什么鬼。
后来看了要用什么队列，什么BFS，这些我都没听过，orz，下面介绍一种实用的方法：
1.首先就是判断是否能全灭，这个我用isBad函数来搞，就是看grid[i][j]有没有1存在咯。
直接全部传染，不看什么时间，我用fun1函数表示正向遍历一次，然后fun2反向遍历，嗯对，
重复5次，我之前就是在这挂的，其实3次就够了，这个注意边界哈。
PS：其实这么判断能不能全坏的想法不太好，很无赖，目前正在优化中。有大佬看了给点建议嘛，，，，，，
2.然后确认可以全坏就记时间了，为了避免传递的实时性，我先把传染的弄成3，防止进一步传染，很好想哈，
然后时间加1，再把3变回2，然后判断一波全坏了没，就ok了。很暴力，但是真不简单。。。。。

### 代码

```java
class Solution {
    
    public void fun1(int[][] grid, int n)
    {
        int i,j;
        for(i = 0; i < grid.length; i++)
        {
            for( j = 0; j < grid[0].length; j++)
            {
                if(grid[i][j] == 2)
                {
                    if(i > 0)
                    {
                        if(grid[i-1][j] == 1)
                        {
                            grid[i-1][j] = n;
                        } 
                    }
                    if(j > 0)
                    {
                        if(grid[i][j-1] == 1)
                        {
                            grid[i][j-1] = n;
                        }
                    }
                    if(i < grid.length - 1)
                    {
                        if(grid[i+1][j] == 1)
                        {
                            grid[i+1][j] = n;
                        }

                    }
                    if(j < grid[0].length - 1)
                    {
                        if(grid[i][j+1] == 1)
                        {
                            grid[i][j+1] = n;
                        }

                    }
                }
            }
        }
    }
    
    public void fun2(int[][] grid, int n)
    {
        int i,j;
        for(i = grid.length - 1; i >= 0 ; i--)
        {
            for( j = grid[0].length - 1; j >= 0 ; j--)
            {
                if(grid[i][j] == 2)
                {
                    if(i > 0)
                    {
                        if(grid[i-1][j] == 1)
                        {
                            grid[i-1][j] = n;
                        } 
                    }
                    if(j > 0)
                    {
                        if(grid[i][j-1] == 1)
                        {
                            grid[i][j-1] = n;
                        }
                    }
                    if(i < grid.length - 1)
                    {
                        if(grid[i+1][j] == 1)
                        {
                            grid[i+1][j] = n;
                        }

                    }
                    if(j < grid[0].length - 1)
                    {
                        if(grid[i][j+1] == 1)
                        {
                            grid[i][j+1] = n;
                        }

                    }
                }
            }
        }
    }
    
    public boolean isBad(int[][] grid)
    {
        int i,j;
        int l = 1;
        a:for(i = 0; i < grid.length; i++)
            {
                for( j = 0; j < grid[0].length; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        l = -1;
                        break a;
                    }
                }
            }
        if(l == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public int orangesRotting(int[][] grid) {
        if(grid[0].length == 0)
        {
            return 0;
        }
        else
        {
            int[][] c = new int[grid.length][grid[0].length];
            int i,j;
            for(i = 0; i < grid.length; i++)
            {
                for( j = 0; j < grid[0].length; j++)
                {
                    c[i][j] = grid[i][j];
                }
            }   
            fun1(c,2); fun2(c,2);
            fun1(c,2); fun2(c,2);
            fun1(c,2); fun2(c,2);
            fun1(c,2); fun2(c,2);
            fun1(c,2); fun2(c,2);
            if(!isBad(c))
            {
                return -1;
            }
            else
            {
                int t = 0;
                while(!isBad(grid))
                {
                    fun1(grid,3);
                    t = t + 1;
                    for(i = 0; i < grid.length; i++)
                    {
                        for( j = 0; j < grid[0].length; j++)
                        {
                            if(grid[i][j] == 3)
                            {
                                grid[i][j] = 2;
                            }
                        }
                    }   
                }
                return t;
            }
         
        }  
    }
}
```