```
class Solution {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        val rowSet = HashSet<Char>()
        val colSet = HashSet<Char>()
        val nightSet = HashSet<Char>()
        for (rowIndex in 0 until board.size) {
            for (colIndex in 0 until board.size) {
                //行
                if ('.' != board[rowIndex][colIndex]) {
                    if (!rowSet.add(board[rowIndex][colIndex]))
                        return false
                }
                //列
                if ('.' != board[colIndex][rowIndex]) {
                    if (!colSet.add(board[colIndex][rowIndex]))
                        return false
                }
                //九宫格
                if ('.' != board[colIndex / 3 + rowIndex / 3 * 3][rowIndex % 3 * 3 + colIndex % 3]) {
                    if (!nightSet.add(board[colIndex / 3 + rowIndex / 3 * 3][rowIndex % 3 * 3 + colIndex % 3]))
                        return false
                }
            }
            rowSet.clear()
            colSet.clear()
            nightSet.clear()
        }
        return true
    }
}
```
