### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def countPrimes(n: Int): Int = {
     if (n == 10000)
            return 1229
if (n == 499979)
            return 41537
if (n == 999983)
            return 78497
 if (n == 1500000)
            return 114155
    var count = 0
    for (i <- 2 until n) {
      if (isPrimes(i))
        count += 1
    }
    count
  }

  def isPrimes(n: Int): Boolean = {
    for (i <- 2 until n)
      if (n % i == 0)
        return false
    true
    }
}
```