```scala
object Solution {
  def movesToChessboard(board: Array[Array[Int]]): Int = {
    var rowSum = 0
    var colSum = 0
    var rowDiff = 0
    var colDiff = 0
    board.indices.foreach(i => board.indices.foreach(j => if ((board(0)(0) ^ board(i)(0) ^ board(0)(j) ^ board(i)(j)) > 0) return -1))
    board.indices.foreach(i => {
      rowSum += board(0)(i)
      colSum += board(i)(0)
      rowDiff += (if (board(i)(0) == i % 2) 1 else 0)
      colDiff += (if (board(0)(i) == i % 2) 1 else 0)
    })
    if (board.length / 2 > rowSum || rowSum > (board.length + 1) / 2) return -1
    if (board.length / 2 > colSum || colSum > (board.length + 1) / 2) return -1
    if (board.length % 2 > 0) {
      if (rowDiff % 2 > 0) rowDiff = board.length - rowDiff
      if (colDiff % 2 > 0) colDiff = board.length - colDiff
    } else {
      rowDiff = (board.length - rowDiff).min(rowDiff)
      colDiff = (board.length - colDiff).min(colDiff)
    }
    (rowDiff + colDiff) / 2
  }
}
```