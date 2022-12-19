```scala
object Solution {
  def toLowerCase(str: String): String = {
    str.map(i => if (i >= 65 && i <= 90) (i + 32).toChar else i)
  }
}
```
