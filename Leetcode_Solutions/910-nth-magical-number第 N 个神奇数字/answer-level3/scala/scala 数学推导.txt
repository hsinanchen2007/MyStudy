```scala
object Solution {
  def nthMagicalNumber(N: Int, A: Int, B: Int): Int = {
    val lcm: Long = A * B / gcd(A, B)
    val M = 1e9 + 7.toLong
    val len = lcm / A + lcm / B - 1
    val cnt = N / len
    val rem = N % len
    val nearest = rem / (1.0 / A + 1.0 / B)
    val remIdx = math.min(math.ceil(nearest / A) * A, math.ceil(nearest / B) * B).toInt
    ((cnt * lcm + remIdx) % M).toInt
  }

  @scala.annotation.tailrec
  def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
}
```
