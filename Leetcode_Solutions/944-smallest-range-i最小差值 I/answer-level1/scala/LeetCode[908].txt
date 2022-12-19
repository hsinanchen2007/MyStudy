```
object Solution {
  def smallestRangeI(A: Array[Int], K: Int): Int = {
    math.max(A.max - A.min - 2 * K, 0)
  }
}
```
