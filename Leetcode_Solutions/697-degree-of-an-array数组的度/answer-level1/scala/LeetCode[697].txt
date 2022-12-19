```
object Solution {

  case class tmp(cnt: Int, min: Int, max: Int)

  def findShortestSubArray(nums: Array[Int]): Int = {
    var cnt = 0
    var min = Int.MaxValue
    val mymap = scala.collection.mutable.Map[Int, tmp]()
    for (i <- 0 to nums.length - 1) {
      if (!mymap.contains(nums(i))) {
        mymap(nums(i)) = tmp(1, i, i)
      } else {
        val mytmp = mymap(nums(i))
        mymap(nums(i)) = tmp(mytmp.cnt + 1, mytmp.min, i)
      }
    }
    for (item <- mymap) {
      val value: tmp = item._2
      if (value.cnt > cnt) {
        cnt = value.cnt
        min = value.max - value.min + 1
      } else if (value.cnt == cnt) {
        min = math.min(min, value.max - value.min + 1)
      }
    }
    return min
  }
}

```
