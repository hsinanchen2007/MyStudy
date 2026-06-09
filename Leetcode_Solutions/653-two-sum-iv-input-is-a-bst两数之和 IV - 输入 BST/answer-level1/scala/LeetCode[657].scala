```
object Solution {
  def judgeCircle(moves: String): Boolean = {
    val tuple: (Int, Int) = moves.foldLeft((0, 0))((z, x) => {
      x match {
        case 'L' => (z._1 + 1, z._2)
        case 'R' => (z._1 - 1, z._2)
        case 'U' => (z._1, z._2 + 1)
        case 'D' => (z._1, z._2 - 1)
      }
    })
    if (tuple._1 == 0 && tuple._2 == 0) true else false
  }
}

```
