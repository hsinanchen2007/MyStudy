```scala
object Solution {
  def mirrorReflection(p: Int, q: Int): Int = 1 - p / gcd(p, q) % 2 + q / gcd(p, q) % 2

  @scala.annotation.tailrec
  def gcd(p: Int, q: Int): Int = if (q > 0) gcd(q, p % q) else p
}
```