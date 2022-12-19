```
object Solution {
  def hasGroupsSizeX(deck: Array[Int]): Boolean = {
    val intToInt = deck.map(x => (x, 1)).groupBy(_._1).mapValues(x => x.length)
    val distinct: List[Int] = intToInt.values.toList.distinct
    val min: Int = distinct.min
    if (min == 1) return false
    (2 to min) exists (i => distinct.forall(_ % i == 0))
  }
}
```
