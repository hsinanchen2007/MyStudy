```kotlin
class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if (strs.isEmpty()) return ""
        val strSequence = strs.asSequence()
        val minLength = strSequence.map(String::length).min()!!
        val lcpLength = (0 until minLength).asSequence()
            .firstOrNull { i -> !strSequence.map { it[i] }.zipWithNext { a, b -> a == b }.all { it } } ?: minLength
        return strs[0].substring(0, lcpLength)
    }
}
```