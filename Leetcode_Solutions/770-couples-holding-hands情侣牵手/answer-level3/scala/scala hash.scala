```scala
import scala.collection.mutable

object Solution {
  def minSwapsCouples(row: Array[Int]): Int = {
    val m = new mutable.HashMap[Int, Int]()
    (row.indices by 2).foreach(i => func(m, row(i) / 2, row(i + 1) / 2))
    m.size
  }

  @scala.annotation.tailrec
  def func(m: mutable.HashMap[Int, Int], x: Int, y: Int): Unit = {
    val c1 = x.min(y)
    val c2 = x.max(y)
    if (c1 == c2) return
    if (m.contains(c1)) func(m, m(c1), c2) else m(c1) = c2
  }
}
```
