```scala
object Solution {
  def findShortestSubArray(nums: Array[Int]): Int = {
    var res = nums.length
    val arr = nums.groupBy(i => i).map(i => (i._1, i._2.length)).toList.sortBy(i => (-i._2, i._1))
    val t = arr.filter(_._2 == arr.map(_._2).max).map(_._1)
    t.foreach(i => res = res.min(nums.lastIndexOf(i) - nums.indexOf(i) + 1))
    res
  }
}
```
