```scala
object Solution {
  def minFlipsMonoIncr(S: String): Int = {
    var res = Int.MaxValue
    val arr = new Array[Int](S.length + 1)
    S.indices.foreach(i => arr(i + 1) = arr(i) + (if (S(i) == '1') 1 else 0))
    (0 to S.length).foreach(i => res = math.min(res, arr(i) + S.length - i - (arr(S.length) - arr(i))))
    res
  }
}
```
