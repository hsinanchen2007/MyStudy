### 解题思路

```javascript
每次「迁移」操作将会引发下述活动：

位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
```

这三种活动组合后就是：
1、将每行的的数据倒着去交换位置；
2、再将第一列倒着去交换位置。

```javascript         
[1,2,3],           [3,1,2],             [9,1,2],
[4,5,6],   ---->   [6,4,5],   ----->    [3,4,5],
[7,8,9]            [9,8,7]              [6,7,8]
````

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {
    const { length } = grid;
    let len = grid[0].length;
    const changeNum = () => {
        // 将每行的数据倒着交换位置
        for(let i = length - 1; i >= 0; i--){
            for(let j = len - 1; j > 0; j--){
                [grid[i][j],grid[i][j - 1]] = [grid[i][j - 1],grid[i][j]];
            }
        }
        // 将第一列的数据倒着交换位置
        let i = length - 1;
        while(i > 0){
            [grid[i][0],grid[i - 1][0]] = [grid[i - 1][0],grid[i][0]];
            i--;
        }
    }
    let i = 0;
    while(i < k){
        changeNum();
        i++;
    }
    return grid;
};
```