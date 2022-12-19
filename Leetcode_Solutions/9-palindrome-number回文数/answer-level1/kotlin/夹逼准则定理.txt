### 解题思路

前后双指针依次对比

### 代码

```kotlin
class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) return false
    var x = x.toString()
    var i = 0
    var j = x.length-1
    while (i < j) {
        if (x[i++] != x[j--]) {
            return false
        }
    }
    return true
    }
}
```