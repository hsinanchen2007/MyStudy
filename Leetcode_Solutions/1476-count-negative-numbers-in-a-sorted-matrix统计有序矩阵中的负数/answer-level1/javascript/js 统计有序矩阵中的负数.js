1. 思路和之前有一道取有序矩阵中的某个数字思路类似，因为有序矩阵从上到下，从左到右以非递增顺序排列，所以矩阵左下角的数字应处于中间值，选这个数字开始比较的话，大的话可以向右移，小的话可以向上移，属于进可攻退可守。
2. 统计矩阵中负数个数，若一行中一个数字为负，则该数字后面都是负数，无需再循环判断，因此 res += n - j，只递减行序号，若数字非负，再递减列序号

```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    let m = grid.length, n = grid[0].length
    let i = m - 1, j = 0, res = 0
    while(i >= 0 && j < n) {
        if (grid[i][j] < 0) {
            res += n - j
            i--
        } else {
            j++
        }
    }
    return res
};
```
