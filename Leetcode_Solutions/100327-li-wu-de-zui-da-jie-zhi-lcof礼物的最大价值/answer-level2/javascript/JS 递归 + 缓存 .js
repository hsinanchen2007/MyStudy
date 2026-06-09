经典的最大路径问题，可以DP 也可以 递归+缓存，这里贴上 **相对** 不常见的递归
```js
var maxValue = function(grid ) {
    
    if(grid.length === 0 || grid[0].length === 0) return 0
    let memo = new Map()
    //递归从上向下 执行到第一个值结束
    return maxValueCore(grid,grid.length-1,grid[0].length-1)

    function maxValueCore(grid,row,col){
        //如果当前路径无效，则他的值为 0 
        if(!isVaildPath(grid,row,col)) return 0
        //记忆化步骤
        if(memo.has(`${row}:${col}`)) return memo.get(`${row}:${col}`)
        //curMax = prevMax + curVal
        let curMax = Math.max(maxValueCore(grid,row-1,col),maxValueCore(grid,row,col-1)) + grid[row][col]
        //记忆化步骤
        memo.set(`${row}:${col}`,curMax)
        return curMax
    }
};

function isVaildPath(grid,row,col){
    return row >= 0 && row <= grid.length && col >= 0 && col <= grid[0].length
}

```