### 解题思路


### 代码

```kotlin
class Solution {
    fun reverseString(s: CharArray): Unit {
        s.reverse()
    }
}
```
看一下**reverse()**的内部实现
````
public fun CharArray.reverse() {
    val midPoint = (size / 2) - 1
    if (midPoint < 0) return
    var reverseIndex = lastIndex
    for (index in 0..midPoint) {
        val tmp = this[index]
        this[index] = this[reverseIndex]
        this[reverseIndex] = tmp
        reverseIndex--
    }
}
```
