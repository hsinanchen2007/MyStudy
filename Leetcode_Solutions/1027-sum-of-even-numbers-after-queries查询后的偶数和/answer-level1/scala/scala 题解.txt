```scala
object Solution {
  def sumEvenAfterQueries(A: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
    val res = new Array[Int](queries.length)
    var sum = 0
    queries.indices.foreach(i => if (A(i) % 2 == 0) sum += A(i))
    queries.indices
      .foreach(i => {
        val index = queries(i)(1)
        var v = A(index) + queries(i)(0)
        if (A(index) % 2 == 0) sum -= A(index)
        if (v % 2 == 0) sum += v
        A(index) = v
        res(i) = sum
      })
    res
  }
}
```
