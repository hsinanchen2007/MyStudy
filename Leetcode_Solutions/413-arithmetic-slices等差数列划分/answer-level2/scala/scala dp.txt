```scala
object Solution {
  def numberOfArithmeticSlices(A: Array[Int]): Int = {
    var res = 0
    var cur = 0
    (2 until A.length).foreach(i => {
      if (A(i) - A(i - 1) == A(i - 1) - A(i - 2)) {
        cur += 1
        res += cur
      } else cur = 0
    })
    res
  }
}
```
