```scala
object Solution {
  def reorderedPowerOf2(N: Int): Boolean = {
    val sum = func(N)
    (0 until 31).foreach(i => if (func(1 << i) == sum) return true)
    false
  }

  def func(N: Int): Long = {
    var res: Long = 0
    var i = N
    while (i > 0) {
      res += math.pow(10, i % 10).toLong
      i /= 10
    }
    res
  }
}
```
