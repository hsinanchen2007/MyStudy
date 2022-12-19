```
object Solution {
  def isMonotonic(A: Array[Int]): Boolean = {
    if (A.length == 2) return true
    var i = 1
    while (i < A.length && A(i) == A(i - 1)) {
      i += 1
    }
    if (i == A.length) return true
    val flag = A(i) - A(i - 1)
    while (i < A.length) {
      if (flag > 0 && A(i) < A(i - 1)) return false
      if (flag < 0 && A(i) > A(i - 1)) return false
      i += 1
    }
    return true
  }
}
```
