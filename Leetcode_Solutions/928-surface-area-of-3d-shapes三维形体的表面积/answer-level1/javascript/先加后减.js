### 解题思路
此处撰写解题思路
先把每一个格子上所有的面相加，再减去每一个格子之间重叠的面积
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let sum=0;//总面积
    for(let i=0;i<grid.length;i++)//遍历
    {
        for(let j=0;j<grid[i].length;j++)
        {
            if(grid[i][j]!=0)
            {
                sum+=grid[i][j]*4+2;//单个格子上有方块的时候，总的面数（暂时不考虑每个格子的重叠）
            }
            if(i>0)
            {
                let col=Math.min(grid[i][j],grid[i-1][j]);//行之间重叠的面数，是比较矮的那个格子的方块数量，
                sum-=col*2;
            }
            if(j>0)
            {
                let col=Math.min(grid[i][j],grid[i][j-1]);
                sum-=col*2;
            }
        }
    }
    return sum;
};
```