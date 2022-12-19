使用 uint16 , 来作为位图，压缩空间复杂度。

使用了3个 [9]uint16 数组 作为 位图，使用内存固定为 3 * 9 * 2byte = 54byte，空间复杂度为 __O(1)__

两层嵌套for循环，时间复杂度为 __O(1)__

```go
func isValidSudoku(board [][]byte) bool {
    var row, col, block [9]uint16
    var cur uint16
    for i := 0; i < 9; i++ {
        for j := 0; j < 9; j++ {
            if board[i][j] == '.' {
                continue
            }
            cur = 1 << (board[i][j] - '1')  // 当前数字的 二进制数位 位置
            bi := i/3 + j/3*3  // 3x3的块索引号
            if (row[i] & cur) | (col[j] & cur) | (block[bi] & cur) != 0 { // 使用与运算查重
                return false
            }
            // 在对应的位图上，加上当前数字
            row[i] |= cur
            col[j] |= cur
            block[bi] |= cur
        }
    }
    return true
}
```

- 执行用时：0 ms, 在Valid Sudoku的Go提交中击败了100.00% 的用户
- 内存消耗：2.9 MB, 在Valid Sudoku的Go提交中击败了68.54% 的用户