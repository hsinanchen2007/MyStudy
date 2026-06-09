```
object Solution {
  def uncommonFromSentences(A: String, B: String): Array[String] = {
    (A.split(" ") ++ B.split(" ")).map(x => (x, 1)).groupBy(_._1).filter(_._2.size == 1).keys.toArray
  }
}
```
