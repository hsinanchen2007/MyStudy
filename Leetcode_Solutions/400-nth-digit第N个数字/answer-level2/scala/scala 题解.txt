```scala
object Solution {
  def findNthDigit(n: Int): Int = func(n, 1)

  @scala.annotation.tailrec
  def func(n: Int, idx: Int): Int = n match {
    case _: Int if n <= 9 * idx * Math.pow(10, idx - 1) =>
      val t = (Math.pow(10, idx - 1).toInt + (n - 1) / idx).toString
      t((n - 1) % idx) - '0'
    case _ => func(n - 9 * idx * Math.pow(10, idx - 1).toInt, idx + 1)
  }
}
```
