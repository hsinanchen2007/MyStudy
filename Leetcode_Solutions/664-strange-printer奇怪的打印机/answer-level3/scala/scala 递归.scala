```scala
object Solution {
  def strangePrinter(s: String): Int = {
    func(s, 0, s.length - 1, Array.ofDim[Int](s.length, s.length))
  }

  def func(s: String, i: Int, j: Int, arr: Array[Array[Int]]): Int = {
    if (i > j) return 0
    if (arr(i)(j) > 0) return arr(i)(j)
    arr(i)(j) = func(s, i + 1, j, arr) + 1
    (i + 1 to j).foreach(k => {
      if (s(k) == s(i))
        arr(i)(j) = math.min(arr(i)(j), func(s, i + 1, k - 1, arr) + func(s, k, j, arr))
    })
    arr(i)(j)
  }
}
```
