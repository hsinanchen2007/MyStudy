执行用时 : 436 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 : 40.6 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    fun addToArrayForm(A: IntArray, K: Int): List<Int> {
        val sum = ArrayList<Int>()
        var i = A.lastIndex
        var j = K
        var d = 0
        while (i > -1 && j != 0) {
            d += A[i] + j % 10
            sum.add(d % 10)
            d /= 10
            i--
            j /= 10
        }
        while (i > -1) {
            d += A[i]
            sum.add(d % 10)
            d /= 10
            i--
        }
        while (j != 0) {
            d += j % 10
            sum.add(d % 10)
            d /= 10
            j /= 10
        }
        if (d != 0) {
            sum.add(d)
        }
        return sum.reversed()
    }
```
