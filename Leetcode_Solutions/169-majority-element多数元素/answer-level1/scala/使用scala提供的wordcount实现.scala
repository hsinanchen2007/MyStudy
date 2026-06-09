### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def majorityElement(nums: Array[Int]): Int = {
 val half1: Int = nums.length / 2
    var res: Int = 0
    val iterator = nums.toList.map((_, 1)).groupBy((_._1)).mapValues(_.size)
    iterator.foreach((kv) => {
      if (half1.<(kv._2)) {
        res = kv._1
        return res
      }
    })
    0
    }
}
```