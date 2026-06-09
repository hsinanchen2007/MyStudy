```scala
import scala.collection.mutable
import scala.collection.mutable.ListBuffer

object Solution {
  def partitionLabels(S: String): List[Int] = {
    val res = new ListBuffer[Int]
    var start = 0
    var last = 0
    val m = new mutable.HashMap[Char, Int]()
    S.indices.foreach(i => m(S(i)) = i)
    S.indices.foreach(i => {
      last = last.max(m(S(i)))
      if (i == last) {
        res.append(i - start + 1)
        start = i + 1
      }
    })
    res.toList
  }
}
```
