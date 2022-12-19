```scala
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

object Solution {
  def findRestaurant(list1: Array[String], list2: Array[String]): Array[String] = {
    var mn = Int.MaxValue
    var res = new ArrayBuffer[String]()
    val m = new mutable.HashMap[String, Int]()
    list1.indices.foreach(i => m(list1(i)) = i)
    list2.indices.foreach(i => {
      if (m.contains(list2(i))) {
        val sum = i + m(list2(i))
        if (sum == mn) res.append(list2(i))
        else if (sum < mn) {
          mn = sum
          res = ArrayBuffer(list2(i))
        }
      }
    })
    res.toArray
  }
}
```
