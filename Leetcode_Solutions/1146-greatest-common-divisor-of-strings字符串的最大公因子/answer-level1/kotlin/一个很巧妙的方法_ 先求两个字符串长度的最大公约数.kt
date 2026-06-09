执行用时 : 204 ms, 在所有 Kotlin 提交中击败了60.00%的用户
内存消耗 : 33.6 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    fun gcdOfStrings(str1: String, str2: String): String {
        val l1 = str1.length
        val l2 = str2.length
        val gcd = if (l1 >= l2) {
            gcd(l1, l2)
        } else {
            gcd(l2, l1)
        }
        val gcdStr = str1.substring(0, gcd)
        for (i in 1 until str1.length / gcd) {
            if (gcdStr != str1.substring(i * gcd, (i + 1) * gcd)) {
                return ""
            }
        }
        for (i in 0 until str2.length / gcd) {
            if (gcdStr != str2.substring(i * gcd, (i + 1) * gcd)) {
                return ""
            }
        }
        return gcdStr
    }

    private fun gcd(m: Int, n: Int): Int {//最大公约数的欧几里德算法. 循环方式实现.
        var j = m
        var k = n
        var rem = 0
        while (k != 0) {
            rem = j % k
            j = k
            k = rem
        }
        return j
    }
```
