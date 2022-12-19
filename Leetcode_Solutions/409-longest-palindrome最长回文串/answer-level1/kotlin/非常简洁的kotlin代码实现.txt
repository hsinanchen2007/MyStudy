```kotlin
fun longestPalindrome(s: String): Int {
    val map:MutableMap<Char,Int> = mutableMapOf()
    var ans = 0
    for (i in s) {
        if (map.containsKey(i)) {
            map[i] = map[i]!! + 1
        } else {
            map[i] = 1
        }
    }
    map.values.forEach { ans += it / 2 * 2 }
    return if (ans == s.length) ans else ans + 1
}
```
可以看见, 倒数第二行我清算结果值得时候会把奇数进行减一操作, 这样会去除所有只出现一次的字母, 但是可以选一个奇数字母/串作为最中间的元素, 所以判断如果长度和s不一致, 也就是说对某个奇数字母进行了修建, 那就加一
