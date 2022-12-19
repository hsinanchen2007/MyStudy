```scala
object Solution {
  def flipLights(n: Int, m: Int): Int = {
    val t = n.min(3)
    (1 << t).min(1 + m * t)
  }
}
```
