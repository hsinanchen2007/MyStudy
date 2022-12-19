```
object Solution {
  def fairCandySwap(A: Array[Int], B: Array[Int]): Array[Int] = {
    val aSum = A.sum
    val bSum = B.sum
    val diff = aSum - bSum
    for (item <- A) {
      val itemB = item - diff / 2
      if (B.contains(itemB)) {
        return Array(item, itemB)
      }
    }
    return Array(-1, -1)
  }
}
```
