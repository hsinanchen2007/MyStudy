### 解题思路
思路挺简单的，就是先将字符串分解成字符串数组，然后针对每个字符串数组，再进行翻转。难度主要在于初学Kotlin不知道有哪些函数可以用

### 代码

```kotlin
class Solution {
    fun reverseWords(s: String): String {
        var array = s.split(" ")
        println(s.length)
        var sb = StringBuilder(s.length)
        for (item in array) {
            sb.append(item.reversed()).append(" ")
        }
        println(sb.toString())
        return sb.toString().trim()
    }
}
```