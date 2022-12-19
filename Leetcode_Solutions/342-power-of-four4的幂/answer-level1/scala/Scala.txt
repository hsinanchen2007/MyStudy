### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def isPowerOfFour(num: Int): Boolean = {
        var i: Double = num
    var count: Int = 0
    if (i == 1 || i == 4) return true
    if (i == 2 || i == 3) return false
    while (i > 4) {
      i = i / 4

      if (i % 4 == 0) {
        count += 1

      } else {
        return false
      }
    }
    if (count >= 1) {
      return true
    }
    false
    }
}
```