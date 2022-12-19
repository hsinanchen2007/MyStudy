执行用时 :212 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 :37.2 MB, 在所有 Kotlin 提交中击败了100.00%的用户
```

    fun largestUniqueNumber(A: IntArray): Int {
        if (A.size == 1) {
            return A[0]
        }
        A.sort()
        var res = -1
        var index = A.lastIndex
        while (index > -1) {
            if (index == A.lastIndex) {
                if (A[index] != A[index - 1]) {
                    return A.last()
                } else {
                    index--
                }
            } else if (index == 0) {
                if (A[index] != A[index + 1]) {
                    return A.first()
                } else {
                    break
                }
            } else {
                if (A[index] != A[index - 1] && A[index] != A[index + 1]) {
                    return A[index]
                } else {
                    index--
                }
            }
        }
        return res
    }
```
