```
object Solution {
  def pow(in: Int, num: Int): Int = {
    var ret = 1
    var _num = num
    while (_num > 0) {
      ret *= in
      _num -= 1
    }
    ret
  }

  def powerfulIntegers(x: Int, y: Int, bound: Int): List[Int] = {
    import scala.collection.mutable.ArrayBuffer
    val mymap = scala.collection.mutable.Map[Int, Int]()
    val myArrayBuffer = new ArrayBuffer[Int]()
    val xLimit = if (x != 1) (math.log(bound) / math.log(x)).toInt else 1
    val yLimit = if (y != 1) (math.log(bound) / math.log(y)).toInt else 1
    for (i <- 0 to xLimit; j <- 0 to yLimit) {
      val value = pow(x, i) + pow(y, j)
      if (value <= bound) {
        mymap(value) = 1
      }
    }
    mymap.keys.toList
  }
}
```
