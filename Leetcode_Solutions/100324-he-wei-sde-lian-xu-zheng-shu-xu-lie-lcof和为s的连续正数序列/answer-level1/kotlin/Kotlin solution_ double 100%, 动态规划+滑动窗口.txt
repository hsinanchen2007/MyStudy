执行用时 : 280 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 : 32.6 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    fun findContinuousSequence(target: Int): Array<IntArray> {
        val res = ArrayList<IntArray>()
        var sum = 0
        val end = (target + 1) / 2
        for (i in 1..end) {
            sum = 0
            for (j in i..end) {
                sum += j
                if (sum >= target) {
                    if (sum == target) {
                        val sub = IntArray(j - i + 1)
                        for (k in i..j) {
                            sub[k - i] = k
                        }
                        res.add(sub)
                    }
                    break
                }
            }
        }
        return res.toTypedArray()
    }
```
