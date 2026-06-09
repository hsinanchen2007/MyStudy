### 解题思路
正整数为什么会有0

### 代码

```scala
object Solution {
    def checkPerfectNumber(num: Int): Boolean = {
    var res = 0
    if (num == 1 || num==0) return false
    for (i <- 1 until num) {
      if (num % i == 0)
        res += i
    }
    if(res==num)
      return true
    false
    }
}
```