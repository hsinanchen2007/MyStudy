### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun minimumLengthEncoding(words: Array<String>): Int {
        val list = words.sortedWith(Comparator {
                o1, o2 -> if (o1.length > o2.length) -1 else if (o1.length == o2.length) 0 else 1
        })
        val set = HashSet<String>()
        var ans = 0
        for (item in list) {
            if (item in set) {
                continue
            }
            ans += item.length + 1
            for (i in 0 until item.length - 1) {
                set.add(item.substring(i))
            }
        }
        return ans
    }
}
```