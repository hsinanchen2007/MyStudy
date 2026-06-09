### 解题思路
通过ArrayBuffer存储数值，通过while实现数组的循环遍历，直到还剩下一个元素
通过计算角标，删除指定的元素
### 代码

```scala
import scala.collection.mutable.ArrayBuffer

object Solution {
  def lastRemaining(n: Int, m: Int): Int = {
    val arr = ArrayBuffer[Int]()
    for (i <- 0 until n) arr += i
    var carryOverNum = n
    var indexNum = 0
    //数组循环遍历
    while (carryOverNum > 1) {
      if (indexNum + m -1 < carryOverNum) {
        indexNum = m + indexNum -1
      } else {
        indexNum = (indexNum + m -1) % carryOverNum
      }
      arr.remove(indexNum)
      carryOverNum -= 1
    }
    arr.head
  }
}
```