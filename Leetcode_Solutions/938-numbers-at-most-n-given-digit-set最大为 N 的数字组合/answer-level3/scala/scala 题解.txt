```scala
object Solution {
  def atMostNGivenDigitSet(D: Array[String], N: Int): Int = {
    var res = 0
    val s = N.toString
    (1 until s.length).foreach(i => res += math.pow(D.length, i).toInt)
    s.indices.foreach(i => {
      var flag = false
      D.foreach(j => {
        if (j(0) < s(i)) res += math.pow(D.length, s.length - 1 - i).toInt
        else if (j(0) == s(i)) flag = true
      })
      if (!flag) return res
    })
    res + 1
  }
}
```
