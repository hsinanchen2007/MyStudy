```scala
object Solution {
  def reachNumber(target: Int): Int = {
    val n = math.ceil((math.sqrt(1 + 8.0 * math.abs(target)) - 1) / 2).toInt
    val d = n * (n + 1) / 2 - target
    n + (d % 2) * (n % 2 + 1)
  }
}
```
