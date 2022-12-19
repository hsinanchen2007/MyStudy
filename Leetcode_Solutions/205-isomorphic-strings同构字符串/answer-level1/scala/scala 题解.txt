```scala
object Solution {
  def isIsomorphic(s: String, t: String): Boolean = s match {
    case "" => true
    case _ =>
      val v = (s zip t).distinct
      v.map(_._1).length == v.map(_._1).distinct.length && v.map(_._2).length == v.map(_._2).distinct.length
  }
}
```
