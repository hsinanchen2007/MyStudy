```
object Solution {
  def distance(a: Array[Int], b: Array[Int]): Int = {
    (a zip b).map(x => (x._1 - x._2) * (x._1 - x._2)).sum
  }

  def numberOfBoomerangs(points: Array[Array[Int]]): Int = {
    var num = 0
    val mymap = scala.collection.mutable.Map[Int, Int]()
    for (item <- points) {
      mymap.clear()
      for (item2 <- points) {
        val i: Int = distance(item, item2)
        if (mymap.contains(i)) mymap(i) += 1
        else mymap(i) = 1
      }
      num += mymap.filter(_._2 > 1).map(x => x._2 * (x._2 - 1)).sum
    }
    num
  }
}
```
