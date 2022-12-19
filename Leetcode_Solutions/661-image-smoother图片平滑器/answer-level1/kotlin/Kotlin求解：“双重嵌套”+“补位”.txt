

思路：“双重嵌套”+“补位”

1. 创建一个新的矩阵，双重嵌套遍历矩阵。
2. 通过“补位”使原矩阵中每个单位周围有8个单位格。
3. 在双重嵌套最内部计算单位的平均值，通过单元在矩阵中的坐标判断是否是“补位”单元，来计算平均值。

```
class Solution {
    fun imageSmoother(M: Array<IntArray>): Array<IntArray> {
        if (M.isEmpty() || M[0].isEmpty()) return M
        fun getEl(row: Int, col: Int): Int {
            return when {
                row < 0 || row >= M.size -> -1
                col < 0 || col >= M[0].size -> -1
                else -> M[row][col]
            }
        }
        var elCount = 0
        var elSum = 0
        fun handle(el: Int) {
            if (el >= 0) {
                elCount++
                elSum += el
            }
        }
        val resetArray = arrayOfNulls<IntArray>(M.size)
        for (row in M.indices) {
            resetArray[row] = IntArray(M[0].size) { col ->
                elCount = 0
                elSum = 0
                handle(getEl(row - 1, col - 1))
                handle(getEl(row - 1, col))
                handle(getEl(row - 1, col + 1))
                handle(getEl(row, col - 1))
                handle(getEl(row, col))
                handle(getEl(row, col + 1))
                handle(getEl(row + 1, col - 1))
                handle(getEl(row + 1, col))
                handle(getEl(row + 1, col + 1))

                elSum / elCount
            }
        }
        return resetArray as Array<IntArray>
    }
}
```

忘记给执行结果截图了，手动写下。

1. 执行用时 : 392 ms, 在所有 Kotlin 提交中击败了 100.00% 的用户
2. 内存消耗 : 38.3 MB, 在所有 Kotlin 提交中击败了 100.00% 的用户
