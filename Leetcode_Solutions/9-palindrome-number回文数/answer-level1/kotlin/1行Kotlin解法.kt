```kotlin
class Solution {
    fun isPalindrome(x: Int): Boolean =
        x.toString().let { it == it.reversed() }
}
```