```scala
object Solution {
  def isNumber(s: String): Boolean = s.trim().matches("[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?")
}
```