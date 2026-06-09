```scala
import scala.collection.mutable.ListBuffer

object Solution {
  def grayCode(n: Int): List[Int] = {
    val res = new ListBuffer[Int]
    (0 until math.pow(2, n).toInt).foreach(i => res.append((i >> 1) ^ i))
    res.toList
  }
}
```
