### 解题思路
只需考虑小于根号c的数

### 代码

```scala
object Solution {
    def judgeSquareSum(c: Int): Boolean = {
      var num = math.sqrt(c).toInt
    var i = 0
    while (i <= num) {
      if (i * i + num * num == c) {
        return true
      } else if (i * i + num * num < c) {
        i += 1
      } else {
        num -= 1
      }
    }
    false  
    }
}
```