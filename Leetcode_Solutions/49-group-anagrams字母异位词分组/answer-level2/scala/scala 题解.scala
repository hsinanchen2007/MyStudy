```scala
object Solution {
  def groupAnagrams(strs: Array[String]): List[List[String]] = strs.map(x => (x.sorted, x)).groupBy(_._1).map(y => y._2.map(_._2).toList).toList
}
```
