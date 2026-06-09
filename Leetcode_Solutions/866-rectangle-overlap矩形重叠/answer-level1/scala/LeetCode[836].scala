```
object Solution {
  def isRectangleOverlap(rec1: Array[Int], rec2: Array[Int]): Boolean = {
    val (x1, y1, x2, y2) = (rec1(0), rec1(1), rec1(2), rec1(3))
    val (xx1, yy1, xx2, yy2) = (rec2(0), rec2(1), rec2(2), rec2(3))
    if (x1 >= xx2 || x2 <= xx1 || y1 >= yy2 || y2 <= yy1) false else true
  }
}
```
