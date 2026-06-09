```scala
object Solution {
  def searchMatrix(matrix: Array[Array[Int]], target: Int): Boolean = {
    if (matrix.isEmpty || matrix(0).isEmpty) return false
    var i = 0
    var j = matrix(0).length - 1
    while (i < matrix.length && j >= 0) {
      if (matrix(i)(j) == target) return true
      else if (matrix(i)(j) > target) j -= 1
      else i += 1
    }
    false
  }
}
```
