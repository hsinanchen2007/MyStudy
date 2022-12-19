思路：从后向前遍历字符，正常情况是前一个字符大于当前字符，正常做加法，当前一个字符小于当前字符，说明是那六种特殊情况，计算两数差然后做和
```
fun romanToInt(s: String): Int {
    val map = hashMapOf('I' to 1, 'V' to 5, 'X' to 10, 'L' to 50, 'C' to 100, 'D' to 500, 'M' to 1000)
    var a = 0
    var index = s.length - 1
    while (index >= 0) {
        if (index > 0 && map[s[index - 1]]!! < map[s[index]]!!) {
            a += (map[s[index]]!! - map[s[index - 1]]!!)
            index -= 2
        } else {
            a += map[s[index]]!!
            index--
        }
    }
    return a
}
```
