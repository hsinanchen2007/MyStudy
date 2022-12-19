### 解题思路
此处撰写解题思路

### 代码

```scala
import scala.collection.mutable.ListBuffer
object Solution {
    def selfDividingNumbers(left: Int, right: Int): List[Int] = {
     val list = new ListBuffer[Int]
    for (i <- left to right) {
      if (isSelfDividingNumbers(i)) {
        list.append(i)
      }
    }
    list.toList
  }

  def isSelfDividingNumbers(n: Int): Boolean = {
    var value:Int = n
    while (value > 0) {
      if (value % 10 != 0 && n % (value % 10) == 0) {
        value /= 10
      } else {
        return false
      }
    }
    true 
    }
}
```