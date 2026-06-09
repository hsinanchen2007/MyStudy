```scala
object Solution {
  def countNumbersWithUniqueDigits(n: Int): Int = {
    if (n == 0) return 1
    var res = 10
    var cnt = 9
    (2 to n).foreach(i => {
      cnt *= (11 - i)
      res += cnt
    })
    res
  }
}
```
