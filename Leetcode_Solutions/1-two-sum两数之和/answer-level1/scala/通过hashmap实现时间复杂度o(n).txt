### 解题思路
hashMap 查找时间效率o(1)，把nums放入hashmap中
遍历nums 判断hashmap中是否存在 target - nums(i)

### 代码

```scala
import scala.collection.mutable

object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val numsMap = new mutable.HashMap[Int, Int]()
        nums.zipWithIndex.foreach(entry => numsMap += entry._1 -> entry._2)
        nums.zipWithIndex.foreach(entry => {
            val num = entry._1
            val idx = entry._2
            val idx2 = numsMap.getOrElse(target - num, -1)
            if (idx2 != -1 && idx2 != idx) {
                return Array(idx, idx2)
            }
        })
        null
    }
}
```