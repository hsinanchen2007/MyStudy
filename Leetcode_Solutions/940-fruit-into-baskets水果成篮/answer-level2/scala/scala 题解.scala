```scala
object Solution {
  def totalFruit(tree: Array[Int]): Int = {
    var res = 0
    var cur = 0
    var cntB = 0
    var a = 0
    var b = 0
    tree.foreach(i => {
      cur = if (i == a || i == b) cur + 1 else cntB + 1
      cntB = if (i == b) cntB + 1 else 1
      if (b != i) {
        a = b
        b = i
      }
      res = res.max(cur)
    })
    res
  }
}
```
