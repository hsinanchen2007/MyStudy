```scala
object Solution {
  def reverseWords(s: String): String = s.trim.split("\\s+").reverse.mkString(" ")
}
```
