### 解题思路
1. 首先记录最末尾的元素，因为移动到最后一次的空格，前面是没有元素了也就是到达(0,0)的边界了，需要使用这个记录的值放进去
2. 开始双层循环，用(row, col-1)的元素，放在(row, col)的位置，但是需要注意边界，具体看代码的逐步注释

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {
    const COL = grid[0].length; //分别记录grid的行数和列数
    const ROW = grid.length;
    function scooch(grid){
        const LAST = grid[ROW-1][COL-1]; //记录最后那个元素
        for(let i=ROW-1; i>=0; i--){ //从最后边开始遍历
            for(let j=COL-1; j>=0; j--){
                let replacement;
                if(j>0){
                    replacement = grid[i][j-1]; //如果j没到达列的最左边也就是0，那么就获取当前的位置-1处的元素
                }else if(i>0){
                    replacement = grid[i-1][COL-1]; //否则既表示已经到了列的0位置，需要用上一行的元素来作替换值
                }else{
                    replacement = LAST; //已经到了最上面那行，并且已经在列的最左边了（0位置），证明已经在左上角的最后一个位置
                }
                grid[i][j] = replacement; //用上一个元素填充当前位置
            }
        }
    }
    while(k-->0){ //位移k次
        scooch(grid);
    }
    return grid;
};
```