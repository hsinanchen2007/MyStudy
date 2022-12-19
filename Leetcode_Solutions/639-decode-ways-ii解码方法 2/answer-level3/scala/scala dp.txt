```scala
object Solution {
  def numDecodings(s: String): Int = {
    var e0: Long = 1
    var e1: Long = 0
    var e2: Long = 0
    var f0: Long = 0
    val M = 1e9 + 7
    s.foreach(i => {
      if (i == '*') {
        f0 = 9 * e0 + 9 * e1 + 6 * e2
        e1 = e0
        e2 = e0
      } else {
        f0 = (if (i > '0') 1 else 0) * e0 + e1 + (if (i <= '6') 1 else 0) * e2
        e1 = (if (i == '1') 1 else 0) * e0
        e2 = (if (i == '2') 1 else 0) * e0
      }
      e0 = f0 % M.toLong
    })
    e0.toInt
  }
}
```
