```
object Solution {
  def binaryGap(N: Int): Int = {
    var max = Int.MinValue
    val tuples = N.toBinaryString.zipWithIndex.filter(_._1 == '1')
    if (tuples.length <= 1) return 0
    for (i <- 1 to tuples.length - 1) {
      max = math.max(max, tuples(i)._2 - tuples(i - 1)._2)
    }
    return max
  }
}
```
