### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def isPowerOfThree(n: Int): Boolean = {
        var i: Double = n
    var count: Int = 0
    if (i == 1 || i == 3) return true
    if (i == 2) return false
    while (i > 3) {
      i = i / 3

      if (i % 3 == 0) {
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