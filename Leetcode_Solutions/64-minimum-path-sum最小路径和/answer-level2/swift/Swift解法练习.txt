# **解法一：**
## 递归 -（超出了时间限制）
一开始想要直接分解子问题。尝试写成一个递归，但是超出了时间限制
主要思路是，从右下角的格子开始，每往上回溯或者往左回溯，就等于又切割这个矩阵问题，变成了去掉一行或者一列的子矩阵，继续求解最小路径和这个子问题，直到矩阵小到只有1 * 1那么路径就是它本身，由此可以写出递归解法
```
    func minPathSum(_ grid: [[Int]]) -> Int {
        let n = grid.count - 1
        let m = grid[0].count - 1
        if m == 0, n == 0 {
            return grid[0][0]
        }else {
            let smallGird = grid.map { row -> [Int] in
                var mapRow = row
                mapRow.removeLast()
                return mapRow
            }
            if m == 0 {
                return grid[n][m] + minPathSum(Array(grid[0..<n]))
            }else if n == 0 {
                return grid[n][m] + minPathSum(smallGird)
            }
            let a = grid[n][m] + minPathSum(Array(grid[0..<n]))
            let b = grid[n][m] + minPathSum(smallGird)
            return min(a,b)
        }
    }
```

## 标准动态规划
正向思考，再通过动态规划计算最优情况，是效率最高的解法，但是由于参数的不可更改性，Swift无法借助数组本身来节省空间
主要思路是，从左上角往下走，右边的格子是通过左边或者上边的格子得来，如果都有的话，那么**当前路径长度 = 就是左边或者上边的格子的最小值 + 格子本身**。如果有一个缺失的话，那么**当前路径长度 = 就是左边或者上边存在的格子+ 格子本身**
```
    func minPathSum(_ grid: [[Int]]) -> Int {
        let n = grid.count - 1
        let m = grid[0].count - 1
        var solutions = grid
        for i in 0...n {
            for j in 0...m {
                if i == 0, j == 0 {
                    continue;
                }else if i == 0 {
                    solutions[i][j] += solutions[i][j - 1]
                }else if j == 0 {
                    solutions[i][j] += solutions[i - 1][j]
                }else {
                    solutions[i][j] += min(solutions[i][j - 1], solutions[i - 1][j])
                }
            }
            
        }
        return solutions[n][m]
    }
```



