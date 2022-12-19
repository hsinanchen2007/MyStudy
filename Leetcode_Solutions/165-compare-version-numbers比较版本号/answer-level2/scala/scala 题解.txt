```scala
object Solution {
  def compareVersion(version1: String, version2: String): Int = {
    List(version1, version2).map(_.split('.').map(_.toInt)) match {
      case List(a, b) => a.zipAll(b, 0, 0).dropWhile { case (a, b) => a == b }.toList match {
        case Nil => 0
        case List((a, b), _*) => if (a > b) 1 else -1
      }
    }
  }
}
```
