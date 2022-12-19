```scala
object Solution {
  def findCircleNum(M: Array[Array[Int]]): Int = {
    val arr = M.indices.toArray

    @scala.annotation.tailrec
    def func(i: Int): Int = if (arr(i) != i) func(arr(i)) else i

    M.indices.flatMap(i => M.indices.map(j => if (M(i)(j) == 1) arr(func(i)) = func(j)))
    arr.zipWithIndex.count(x => x._1 == x._2)
  }
}
```
