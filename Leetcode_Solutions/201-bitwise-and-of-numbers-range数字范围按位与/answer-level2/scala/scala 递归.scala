```scala
object Solution {
  def rangeBitwiseAnd(m: Int, n: Int): Int = {
    if (n > m) rangeBitwiseAnd(m / 2, n / 2) << 1 else m
  }
}
```
