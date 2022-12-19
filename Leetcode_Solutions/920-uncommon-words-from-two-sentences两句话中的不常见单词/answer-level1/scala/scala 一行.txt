```scala
object Solution {
  def uncommonFromSentences(A: String, B: String): Array[String] = {
    (A + " " + B).split(" ").map((_, 1)).groupBy(_._1).filter(_._2.length == 1).keys.toArray
  }
}
```
