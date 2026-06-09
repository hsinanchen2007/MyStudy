```scala
object Solution {
  def findIntegers(num: Int): Int = {
    var res = 0
    var k = 31
    var pre = 0
    val f = new Array[Int](32)
    f(0) = 1
    f(1) = 2
    (2 until 31).foreach(i => f(i) = f(i - 2) + f(i - 1))
    while (k >= 0) {
      if ((num & (1 << k)) > 0) {
        res += f(k)
        if (pre > 0) return res
        pre = 1
      } else pre = 0
      k -= 1
    }
    res + 1
  }
}
```
