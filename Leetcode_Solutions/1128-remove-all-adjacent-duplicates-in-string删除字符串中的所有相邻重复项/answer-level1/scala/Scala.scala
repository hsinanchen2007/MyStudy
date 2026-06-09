### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def removeDuplicates(S: String): String = {
    val res = new StringBuilder()
    var size = 0
    for (i <- 0 until S.length) {
      if (size != 0 && res.charAt(size - 1) == S.charAt(i)) {
        size -= 1
        res.deleteCharAt(size)
      }
      else {
        res.append(S.charAt(i))
        size += 1
      }
    }
    res.toString()
    }
}
```