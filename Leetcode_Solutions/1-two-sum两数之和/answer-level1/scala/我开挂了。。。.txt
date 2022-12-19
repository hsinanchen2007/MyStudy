### 解题思路
各种算子转换，仅供娱乐（zhuangbi）

### 代码

```scala
object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val map = nums.zipWithIndex
    map.filter(elem => map.exists(kv=>kv._1==target - elem._1&&kv._2!=elem._2)).map(_._2)
  }
}
```