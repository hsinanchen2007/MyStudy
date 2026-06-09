```scala
object Solution {
  def isSelfCrossing(x: Array[Int]): Boolean = {
    (3 until x.length).foreach(i => {
      if (x(i) >= x(i - 2) && x(i - 3) >= x(i - 1)) return true
      if (i >= 4 && (x(i - 1) == x(i - 3)) && x(i) >= x(i - 2) - x(i - 4)) return true
      if (i >= 5 && x(i - 2) >= x(i - 4) && x(i - 3) >= x(i - 1) && x(i - 1) >= x(i - 3) - x(i - 5) && x(i) >= x(i - 2) - x(i - 4)) return true
    })
    false
  }
}
```
