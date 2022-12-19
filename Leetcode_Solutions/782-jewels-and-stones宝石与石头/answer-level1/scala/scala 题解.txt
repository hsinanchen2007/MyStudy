```scala
object Solution {
  def numJewelsInStones(J: String, S: String): Int = {
    S.count(i => J.contains(i))
  }
}
```
