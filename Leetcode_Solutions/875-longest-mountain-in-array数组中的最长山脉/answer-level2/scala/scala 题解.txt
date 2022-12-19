```scala
object Solution {
  def longestMountain(A: Array[Int]): Int = {
    var res = 0
    (1 until A.length - 1).foreach(i => {
      if (A(i - 1) < A(i) && A(i + 1) < A(i)) {
        var left = i - 1
        var right = i + 1
        while (left > 0 && A(left - 1) < A(left)) left -= 1
        while (right < (A.length - 1) && A(right) > A(right + 1)) right += 1
        res = res.max(right - left + 1)
      }
    })
    res
  }
}
```
