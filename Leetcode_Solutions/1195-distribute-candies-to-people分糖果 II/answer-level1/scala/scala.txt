```scala
import scala.util.control.Breaks._

object Solution {
  def distributeCandies(candies: Int, num_people: Int): Array[Int] = {
    val res = Array.fill(num_people)(0)
    var cnt = 0
    var c = candies
    while (c > 0) {
      breakable {
        (0 until num_people).foreach(i => {
          var t = num_people * cnt + i + 1
          if (c <= t) t = c
          res(i) += t
          c -= t
          if (c <= 0) break
        })
      }
      cnt += 1
    }
    res
  }
}
```