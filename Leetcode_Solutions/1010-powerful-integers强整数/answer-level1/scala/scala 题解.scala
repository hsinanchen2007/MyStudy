```scala
object Solution {
  def powerfulIntegers(x: Int, y: Int, bound: Int): List[Int] = {
    if (bound < 2) return List[Int]()
    if (x == 1 && y == 1) List[Int](2)
    else if (x == 1 && y > 1) (0 to func(y, bound - 1)).map(i => 1 + Math.pow(y, i).toInt).toList
    else if (y == 1 && x > 1) (0 to func(x, bound - 1)).map(i => 1 + Math.pow(x, i).toInt).toList
    else (0 to func(x, bound - 1)).flatMap(i => (0 to func(y, bound - 1)).map(j => (Math.pow(x, i) + Math.pow(y, j)).toInt)).toList.distinct.filter(_ <= bound)
  }

  @scala.annotation.tailrec
  def func(base: Int, bound: Int, ans: Int = 0): Int = if (bound >= base) func(base, bound / base, ans + 1) else ans

}
```
