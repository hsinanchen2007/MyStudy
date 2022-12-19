```
object Solution {
  def maxCount(m: Int, n: Int, ops: Array[Array[Int]]): Int = {
    if (ops.length == 0) return m * n
    val min1 = ops.map(x => x(0)).min
    val min2 = ops.map(x => x(1)).min
    min1 * min2
  }
}

```
