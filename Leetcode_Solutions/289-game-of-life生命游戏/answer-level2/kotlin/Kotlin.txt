### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    var m = 0
    var n = 0
    fun gameOfLife(board: Array<IntArray>): Unit {
        if (board.isEmpty()) return
        // init
        m = board.lastIndex
        n = board[0].lastIndex

        for (c in 0..board.lastIndex) {
            for (r in 0..board[c].lastIndex) {
                if (board[c][r] == 0 && isRevival(board, c, r)) {
                    board[c][r] = 2 // 2 复活的细胞
                }
                if (board[c][r] == 1 && isDeath(board, c, r)) {
                    board[c][r] = -1 // 死亡的细胞
                }
            }
        }

        // 改变 标记值
        for (c in 0..board.lastIndex) {
            for (r in 0..board[c].lastIndex) {
                if (board[c][r] == 2) {
                    board[c][r] = 1
                }
                if (board[c][r] == -1) {
                    board[c][r] = 0
                }
            }
        }

    }

    private fun isDeath(board: Array<IntArray>, c: Int, r: Int):Boolean {
        val revivalSum = getRevivalSum(board, c, r)
        if (revivalSum == 2 || revivalSum == 3) return false
        return true
    }


    private fun isRevival(board: Array<IntArray>, c: Int, r: Int): Boolean {
        val revivalSum = getRevivalSum(board, c, r)
        if (revivalSum == 3) return true
        return false
    }

    private fun getRevivalSum(board: Array<IntArray>, c: Int, r: Int): Int {
        var revivalSum = 0
        for (column in -1..1) {
            for (row  in -1..1) {
                if (row == 0 && column == 0) continue
                if (c + column < 0 || c + column > m) break
                if (r + row < 0  || r + row > n) continue
                if (board[c + column][r + row] == 1 || board[c + column][r + row] == -1){
                    revivalSum++
                }

            }
        }
        return revivalSum
    }

}
```