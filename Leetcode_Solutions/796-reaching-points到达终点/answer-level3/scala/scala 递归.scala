```scala
object Solution {
  @scala.annotation.tailrec
  def reachingPoints(sx: Int, sy: Int, tx: Int, ty: Int): Boolean = {
    if (tx < sx || ty < sy) return false
    if (tx == sx && (ty - sy) % sx == 0) return true
    if (ty == sy && (tx - sx) % sy == 0) return true
    reachingPoints(sx, sy, tx % ty, ty % tx)
  }
}
```
