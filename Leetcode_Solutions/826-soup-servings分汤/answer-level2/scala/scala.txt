```scala
import scala.collection.mutable

object Solution {
  private val m = new mutable.HashMap[String, Double]()

  def soupServings(N: Int): Double = if (N >= 4800) 1.0 else func(N, N)

  def func(a: Int, b: Int): Double = {
    if (a <= 0 && b <= 0) return 0.5
    if (a <= 0) return 1.0
    if (b <= 0) return 0
    val spoon = a.toString + ":" + b.toString
    if (!m.contains(spoon))
      m(spoon) = 0.25 * (func(a - 100, b) + func(a - 75, b - 25) + func(a - 50, b - 50) + func(a - 25, b - 75))
    m(spoon)
  }
}
```