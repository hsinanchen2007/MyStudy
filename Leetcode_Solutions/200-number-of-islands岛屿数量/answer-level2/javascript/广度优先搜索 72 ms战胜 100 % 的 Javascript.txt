执行用时 : 72 ms, 在Number of Islands的JavaScript提交中击败了100.00% 的用户
内存消耗 : 38.5 MB, 在Number of Islands的JavaScript提交中击败了44.55% 的用户

注意一下，不需要判断九宫格，只要上下左右即可。

思路简述：先做一个遍历，如果是岛屿，开始对该点做BFS，最开始写的时候有个误区，想要一次性保存下该岛屿的点，最后一次性做标记，结果导致死循环，因为你结束条件是四周没有岛屿，因此每次一搜到1就要做标记。

下面的BFS思想，先对该点做标记2，做完后，向四个方向扩展，直到都不存在岛屿，即四周都是0，返回主算法

还有一个小点，我最开始在findl最后写了一个return，原意就是当四周都为0直接return，以为可以节省时间，但是最后运行时间还更长了

```
/**
 * @param {character[][]} grid
 * @return {number}
 */
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let h = grid.length;
    if(grid==[]||h==0)
        {
            return 0
        }
    let l = grid[0].length,count=0;
    if(l==0){return 0}
    for(let i = 0;i<h;i++)
        {
            for(let j =0;j<l;j++)
                {
                    if(grid[i][j]=='1')
                        {
                            findl(i,j,grid)
                            count++;
                        }
                }
        }
    return count
};
var findl = function(i,j,grid)
    {
        let h = grid.length,l=grid[0].length;
        grid[i][j]=2
        if(i>h-1&&j>l-1)
            {return}
        if(i>0 && grid[i-1][j]=='1')
            {
                findl(i-1,j,grid)
            }
        if(i<h-1 && grid[i+1][j]=='1')
            {
                findl(i+1,j,grid)
            }
        if(j>0&&grid[i][j-1]=='1')
            {
                findl(i,j-1,grid)
            }
        if(j<l-1&&grid[i][j+1]=='1')
            {
                findl(i,j+1,grid)
            }
    }
```