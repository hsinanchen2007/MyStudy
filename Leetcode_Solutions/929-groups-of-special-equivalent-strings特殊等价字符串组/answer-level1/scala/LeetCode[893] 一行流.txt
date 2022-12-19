```
object Solution {
  def numSpecialEquivGroups(A: Array[String]): Int = {
    A.map(x => x.zipWithIndex.map(y => (y._2 % 2, y._1))
.groupBy(_._1).mapValues(l => l.map(_._2).sorted.mkString))
.map(x => x.mkString).toSet.size
  }
}
```


```
object Solution {
  def numSpecialEquivGroups(A: Array[String]): Int = {
    A.map(str => {
      val tuple = str.zipWithIndex.partition(_._2 % 2 == 0)
      tuple._1.map(_._1).sorted.mkString + ":" + tuple._2.map(_._1).sorted.mkString
    }).distinct.size
  }
}
```
