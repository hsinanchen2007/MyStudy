```scala
object Solution {
  def frequencySort(s: String): String = s match {
    case "" => ""
    case _ => s.groupBy(i => i).values.toArray.sortBy(-_.length).reduce(_ + _)
  }
}
```
