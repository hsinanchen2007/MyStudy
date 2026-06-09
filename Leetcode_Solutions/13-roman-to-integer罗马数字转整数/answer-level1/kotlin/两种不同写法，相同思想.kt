### 解题思路
解法一：后一位大于前一位，用后一位的值减去前一位的值，然后 `i += 2` 跳过两个字符；
解法二：参考[这边的代码](https://leetcode-cn.com/problems/roman-to-integer/solution/javaluo-ma-shu-zi-zhuan-zheng-shu-bu-yong-cun-chu-/)，每遇到一位都去检查前一位是否大于等于后一位，如果不是的话，减去当前位的值。

### 代码

```kotlin
class Solution {
    val map: Map<Char, Int> = object : HashMap<Char, Int>() {
        init {
            put('I', 1)
            put('V', 5)
            put('X', 10)
            put('L', 50)
            put('C', 100)
            put('D', 500)
            put('M', 1000)
        }
    }

    // #1
    // fun romanToInt(s: String): Int {
    //     if (s.length == 0) {
    //         return 0
    //     } 
    //     var i = 0
    //     var sum = 0
    //     while (i < s.length) {
    //         val first = map.getOrDefault(s.get(i), 0)
    //         val second = if (i == s.length - 1) 0 else map.getOrDefault(s.get(i + 1), 0)

    //         val isReverse = first < second
    //         sum += if (isReverse) second - first else first
    //         i += if (isReverse) 2 else 1
    //     }
    //     return sum;
    // }

    // #2
    fun romanToInt(s: String): Int {
        if (s.length == 0) {
            return 0
        } 

        var i = 0
        var sum = 0
        while (i < s.length) {
            val first = map.get(s.get(i)) ?: 0
            if (i == s.length - 1) {
                sum += first
            } else {
                val second = map.get(s.get(i + 1)) ?: 0
                sum += if (first >= second) first else -first
            }
            i++
        }
        return sum
    }
}
```