### 解题思路
此处撰写解题思路

### 代码

```scala
import scala.collection.mutable

object Solution {
    def lengthOfLongestSubstring(s: String): Int = {
        if (s == null || s.isEmpty) return 0
        var result, idx = 0
        val substringSet = new mutable.HashMap[Char, Int]()
        val length = s.length
        while (idx < length) {
            val c = s.charAt(idx)
            if (substringSet.contains(c)) {
                result = result.max(substringSet.size)
                idx = substringSet.get(c).get
                substringSet.clear()
            } else {
                substringSet.put(c, idx)
            }
            idx += 1
        }
        result = result.max(substringSet.size)
        result
    }
}
```