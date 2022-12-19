```scala
object Solution {
  def orderlyQueue(S: String, K: Int): String = K match {
    case 1 => func(S)
    case _ => S.sorted
  }

  def func(str: String): String = {
    var res = str
    (1 until str.length).foreach(i => {
      val t = str.substring(i) + str.substring(0, i)
      if (t < res) res = t
    })
    res
  }
}
```
