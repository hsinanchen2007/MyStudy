### 解题思路
scala解法 使用hashmap的key存储数字的每一个元素,value存储元素个数

### 代码

```scala
import scala.collection.mutable
object Solution {
    def findRepeatNumber(nums: Array[Int]): Int = {
    var res: Int = 0
    val data: mutable.Map[Int, Int] = new mutable.HashMap[Int, Int]()
    for (num <- nums) {
      if (!data.contains(num)) {
        data.put(num, 1)
      } else {
        val res: Int = data.getOrElse(num, -1)
        data.put(num, res + 1)
      }
    }
    data.keys.foreach { i =>
      if (data(i) > 1) {
        res = i

      }
    }
    print(res)
    res
  }
}
```