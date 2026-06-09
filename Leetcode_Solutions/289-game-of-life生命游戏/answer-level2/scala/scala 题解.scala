```scala
object Solution {
  def gameOfLife(board: Array[Array[Int]]): Unit = {
    val n = if (board.length > 0) board(0).length else 0
    val dx = Array(-1, -1, -1, 0, 1, 1, 1, 0)
    val dy = Array(-1, 0, 1, 1, 1, 0, -1, -1)
    board.indices.foreach(i => (0 until n).foreach(j => {
      var cnt = 0
      (0 until 8).foreach(k => {
        val x = i + dx(k)
        val y = j + dy(k)
        if (x >= 0 && x < board.length && y >= 0 && y < n && (board(x)(y) == 1 || board(x)(y) == 2)) cnt += 1
      })
      if (board(i)(j) > 0 && (cnt < 2 || cnt > 3)) board(i)(j) = 2
      else if (board(i)(j) <= 0 && cnt == 3) board(i)(j) = 3
    }))
    board.indices.foreach(i => (0 until n).foreach(j => board(i)(j) %= 2))
  }
}
```
