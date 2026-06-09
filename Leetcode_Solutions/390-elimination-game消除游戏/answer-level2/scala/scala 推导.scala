```scala
object Solution {
  def lastRemaining(n: Int): Int = n match {
    case 1 => 1
    case _ => 2 * (1 + n / 2 - lastRemaining(n / 2))
  }
}
```
