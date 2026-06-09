### 解题思路

题目要求：
1. 数字 1-9 在每一行只能出现一次。
2. 数字 1-9 在每一列只能出现一次。
3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

把上面的条件抽成一个函数，检查当前格子是否能填入`1-9`中的某个数字。

那么，我们要做的就是，检查每个格子，看它是否是'.'，是的话就填入数字，回朔处理，否则忽略。

这里有几个corner case需要处理:
1. 回朔什么时候返回呢？`当前处理的行索引 == 9` 的时候
2. 什么时候换行呢？ `当前处理的列索引 == 9` 的时候

### 代码

```kotlin
class Solution {
    fun solveSudoku(board: Array<CharArray>) {
        backtracker(board, 0, 0)

    }

    private fun backtracker(board: Array<CharArray>, row: Int, col: Int): Boolean {
        // base case
        if (row == 9) {
            return true
        }
        if (col == 9) {
            return backtracker(board, row + 1, 0)
        }

        // 已有数字，忽略
        if (board[row][col] != '.') {
            return backtracker(board, row, col + 1)
        }
        for (i in 1..9) {
            if (!isValid(board, row, col, '0' + i)) {
                continue
            }
            // check valid
            board[row][col] = '0' + i
            if (backtracker(board, row, col + 1)) {
                return true
            }
            board[row][col] = '.'
        }
        return false
    }

    private fun isValid(board: Array<CharArray>, row: Int, col: Int, value: Char): Boolean {
        // 横行不能有重复值
        for (i in 0..8) {
            if (board[row][i] == value) {
                return false
            }
        }
        // 竖行不能有重复值
        for (i in 0..8) {
            if (board[i][col] == value) {
                return false
            }
        }
        // 所在九宫格
        for (i in 0..2) {
            val k = (row / 3) * 3 + (row + i) % 3
            for (j in 0..2) {
                val l = (col / 3) * 3 + (col + j) % 3
                if (board[k][l] == value) {
                    return false
                }
            }
        }

        return true
    }
}
```