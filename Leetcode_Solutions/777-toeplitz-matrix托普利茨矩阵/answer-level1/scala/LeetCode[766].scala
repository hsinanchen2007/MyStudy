```
object Solution {
    def isToeplitzMatrix(matrix: Array[Array[Int]]): Boolean = {
      val rows = matrix.length
      val cols = matrix(0).length
      for (i <- 0 to rows - 2) {
        for (j <- 0 to cols - 2) {
          if(matrix(i)(j)!=matrix(i+1)(j+1))
            return false
        }
      }
      return true
    }
}

```
