题目需要满足条件：

sum (0..i) == sum(i+1..j) == sum(j..A.size-1) == sum / 3

具体拆解条件为
- sum % 3 == 0
- i、j存在
- i < j & j < A.size -1

求sum的时候需要遍历，求sum(0..i)  又得遍历，拿个数组sums都给存起来好了，这样 i  就变成 sums.indexOf(i) != -1 , j  变成 在 sums[i+1 .. sums.size -1] 存在即可。

```
fun canThreePartsEqualSum(A: IntArray): Boolean {
        val sums = IntArray(A.size)
        var sum = 0
        for ((index, value) in A.withIndex()) {
            sum += value
            sums[index] = sum
        }
        if (sums.last() % 3 != 0) return false
        val partSum = sums.last() / 3
        val i = sums.indexOf(partSum)
        if (i == -1) return false
        for (it in i + 1 until sums.size) {
            if (sums[it] == partSum * 2 && it != sums.size - 1) return true
        }
        return false
    }
```
