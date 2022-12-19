### 解题思路
将n转换为Double类型

### 代码

```scala
object Solution {
    def isPowerOfTwo(n: Int): Boolean = {
         var i: Double = n
    var count: Int = 0
    if (i == 1 || i == 2) return true
    while (i > 2) {
      i = i / 2
      
      if (i % 2 == 0) {
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