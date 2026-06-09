### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun romanToInt(s: String): Int {
        var result = 0
        var str = s
        while (str.isNotEmpty()) {
            var tempNum = 0
            if (str.length > 1) {
                tempNum = getValue(str.substring(str.length - 2))
            }
            if (tempNum > 0) {
                result += tempNum
                str = str.substring(0, str.length - 2)
            } else {
                tempNum = getValue(str.substring(str.length - 1))
                result += tempNum
                str = str.substring(0, str.length - 1)
            }
        }
        return result
    }

    fun getValue(s: String): Int {
        return when(s) {
            "M" -> 1000
            "D" -> 500
            "C" -> 100
            "L" -> 50
            "X" -> 10
            "V" -> 5
            "I" -> 1
            "IV" -> 4
            "IX" -> 9
            "XL" -> 40
            "XC" -> 90
            "CD" -> 400
            "CM" -> 900
            else -> 0
        }
    }
}
```