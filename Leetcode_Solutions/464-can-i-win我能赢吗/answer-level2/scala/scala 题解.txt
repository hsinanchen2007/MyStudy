```scala
import scala.collection.mutable

object Solution {
  def canIWin(maxChoosableInteger: Int, desiredTotal: Int): Boolean = {
    if (maxChoosableInteger >= desiredTotal) return true
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false
    val m = new mutable.HashMap[Int, Boolean]()
    func(maxChoosableInteger, desiredTotal, 0, m)

  }

  def func(length: Int, total: Int, used: Int, m: mutable.HashMap[Int, Boolean]): Boolean = {
    if (m.contains(used)) return m(used)
    (0 until length).foreach(i => {
      val cur = 1 << i
      if ((cur & used) == 0)
        if (total <= i + 1 || !func(length, total - (i + 1), cur | used, m)) {
          m(used) = true
          return true
        }
    })
    m(used) = false
    false
  }
}
```
