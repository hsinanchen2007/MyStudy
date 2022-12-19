```
object Solution {
  def findRadius(houses: Array[Int], heaters: Array[Int]): Int = {


    val heatersSorted = heaters.sorted
    var maxMinDis: Int = Int.MinValue

    for (item <- houses) {
      var left = 0
      var right = heatersSorted.size - 1

      var dis = 0
      while (left < right) {
        val mid = (left + right) / 2
        if (heatersSorted(mid) >= item) {
          right = mid
        } else {
          left = mid + 1
        }
      }
      dis = if (left == 0) math.abs(heatersSorted(left) - item)
      else math.min(math.abs(heatersSorted(left) - item), math.abs(heatersSorted(left - 1) - item))
      maxMinDis = math.max(maxMinDis, dis)
    }
    maxMinDis
  }
}

```
