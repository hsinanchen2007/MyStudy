### 解题思路
通过把更新后的状态保存到int倒数第二位中，从而不影响当前的状态判断
时间复杂度: O(mn)，空间复杂度: O(1)

### 代码

```golang
func gameOfLife(board [][]int)  {
    directionArr := [3]int{1, -1, 0}
    // 遍历一次保存状态到低第二位中
    m, n := len(board), len(board[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            count := 0
            for _, k1 := range directionArr {
                for _, k2 := range directionArr {
                    if k1 == 0 && k2 == 0 {
                        continue
                    }
                    row, col := i + k1, j + k2
                    if row >= 0 && row <= m - 1 && col >= 0 && col <= n -1 {
                        count += board[row][col] & 1
                    }
                }
            }
            // 如果当前是活细胞
            if board[i][j] & 1 == 1 {
                if count == 2 || count == 3 {
                    board[i][j] = 3
                }
                // 其他情况不用修改
            } else if count == 3 {
                // 如果当前是死细胞
                board[i][j] = 2
            }
        }
    }

    // 再遍历一遍修改状态
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            board[i][j] >>= 1
        }
    }
}
```