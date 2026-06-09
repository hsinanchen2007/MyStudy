```scala
object Solution {
  def maximalRectangle(matrix: Array[Array[Char]]): Int = {
    if (matrix.isEmpty || matrix(0).isEmpty) return 0
    val height = new Array[Int](matrix(0).length + 1)
    var res = 0
    matrix.indices.foreach(i => {
      val st = new java.util.Stack[Int]
      (0 until matrix(0).length + 1).foreach(j => {
        if (j < matrix(0).length) height(j) = if (matrix(i)(j) == '1') height(j) + 1 else 0
        while (!st.empty() && height(st.peek) >= height(j)) {
          val cur = st.peek
          st.pop
          res = res.max(height(cur) * (if (st.empty()) j else j - st.peek - 1))
        }
        st.push(j)
      })
    })
    res
  }
}
```
