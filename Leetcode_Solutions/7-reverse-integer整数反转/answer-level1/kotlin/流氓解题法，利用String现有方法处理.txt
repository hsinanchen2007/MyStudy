### 解题思路
字符串本身提供反转函数，需要处理的仅有一个符号问题。
同时字符串反转还可以应对更大的数据，比如long类型的数据处理，修改也比较方便。
不过该题应该是考虑算法比较多，所以我这个解法只适合解决问题，对算法能力没什么帮助。。。

### 代码

```kotlin
class Solution {
   fun reverse(x: Int): Int {
        val result = x.toString().replace("-", "")
        val negative = x.toString().contains("-")

        return try {
            if (negative) {
                -result.reversed().toInt()
            } else {
                result.reversed().toInt()
            } 
        } catch (e: Exception) {
            0
        }
    }
}
```