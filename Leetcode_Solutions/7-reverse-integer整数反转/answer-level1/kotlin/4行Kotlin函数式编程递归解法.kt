```kotlin
class Solution {
    tailrec fun reverse(x: Int, y: Long = 0): Int =
        if (x == 0)
            if (y in Int.MIN_VALUE..Int.MAX_VALUE) y.toInt() else 0
        else
            reverse(x / 10, y * 10 + x % 10)
}
```