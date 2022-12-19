```scala
import scala.util.control.Breaks._

object Solution {
  def searchMatrix(matrix: Array[Array[Int]], target: Int): Boolean = {
    if (matrix.isEmpty || matrix(0).isEmpty) return false
    if (target < matrix(0)(0) || target > matrix.last.last) return false
    var x = matrix.length - 1
    var y = 0
    breakable {
      while (true) {
        if (matrix(x)(y) > target) x -= 1
        else if (matrix(x)(y) < target) y += 1
        else return true
        if (x < 0 || y >= matrix(0).length) break
      }
    }
    false
  }
}
```
