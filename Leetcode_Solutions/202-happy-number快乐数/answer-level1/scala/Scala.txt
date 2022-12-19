### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def isHappy(n: Int): Boolean = {
    var fast = n
    var slow = n
    do {
      slow = squareSum(slow)
      fast = squareSum(fast)
      fast = squareSum(fast)
    } while (slow != fast)
    if (fast == 1) true
    else false
  }

  private def squareSum(m: Int): Int = {
    var n: Int = m
    var squaresum = 0
    while (n != 0) {
      squaresum += (n % 10) * (n % 10)
      n /= 10
    }
    squaresum
  }
    
}
```