我的提交执行用时
已经战胜 86.24 % 的 javascript 提交记录

由题可知，每次只能向右或者向下走，因此[0][n]的上一步必定是向右走，而[0][n]的上一步必定是向下，由此可以先确定第一行和第一列的当前最小路径。

对于中间的其他格子，由于上一步有两种可能性，因此需要分别计算左侧格子和上侧格子的最小路径和，并选出较小的一个，即为当前格的最小路径和。


![无标题.png](https://pic.leetcode-cn.com/1d3173439afc3e9b8f4a724475bfbd4b7df9f2b3414aa8a14deab4306ef1d27c-%E6%97%A0%E6%A0%87%E9%A2%98.png)
```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    let l = grid.length,h=grid[0].length;
    let temp = [];
    for(let i=0;i<l;i++)
        {
            temp[i]=[];
        }
    // console.log(temp)
    for(let i = 0;i<l;i++)
        {
            for(let j = 0;j<h;j++)
                {
                    if(i==0&&j==0)
                        {
                            temp[i][j]=grid[i][j]
                        }
                    else if(i==0)
                        {
                            temp[i][j]=temp[i][j-1]+grid[i][j]
                        }
                    else if(j==0)
                        {
                            temp[i][j]=temp[i-1][j]+grid[i][j]
                        }
                    else
                        {
                            temp[i][j]=grid[i][j]+Math.min(temp[i][j-1],temp[i-1][j])
                        }
                }
        }
    // console.log(temp)
    return temp[l-1][h-1]
};
```