### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def countSegments(s: String): Int = {
    var Count = 0;
    for (i <- 0 until s.length) {
      if ((i == 0 || s.charAt(i - 1) == ' ') && s.charAt(i) != ' ') {
        Count += 1
      }
    }
    Count
    }
}
```