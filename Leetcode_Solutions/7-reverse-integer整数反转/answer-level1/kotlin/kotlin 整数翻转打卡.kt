```kotlin
class Solution {
    fun reverse(x: Int): Int {
    var x = x
    var rev:Int = 0
    while(x != 0) {
        if (rev > Int.MAX_VALUE/10) return 0
        if (rev < Int.MIN_VALUE/10) return 0
        rev = rev * 10 + x %10
        x /= 10
    }
    return rev
    }
}
```
