### 解题思路
各位相加暴力求解

### 代码

```scala
object Solution {
    def addDigits(num: Int): Int = {
      var Num: Int = num
    var count = 0
    if (Num < 10)
      return Num
    while (Num >= 10) {
      count = Num / 10 + Num % 10
      Num = count
    }
    count  
    }
}
```