### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def checkRecord(s: String): Boolean = {
      var countA = 0
    var i = 0
    while (i < s.length) {
      if (s.charAt(i) == 'A') {
        countA += 1
        i += 1
      } else {
        i += 1
      }
    }
    if (countA > 1 || s.contains("LLL"))
      return false
    true  
    }
}
```