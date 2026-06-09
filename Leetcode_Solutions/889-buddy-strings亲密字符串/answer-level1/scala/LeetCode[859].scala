```
object Solution {
  def buddyStrings(A: String, B: String): Boolean = {
    if (A.length != B.length) return false
    if (A == B) {
      return A.toArray.toSet.size != A.length
    }
    val mymap = scala.collection.mutable.Map[Int, (Char, Char)]()
    for (i <- 0 to A.length - 1) {
      if (A(i) != B(i))
        mymap(i) = (A(i), B(i))
    }
    if (mymap.size != 2) return false
    val list: List[(Char, Char)] = mymap.values.toList
    val first: (Char, Char) = list(0)
    val second: (Char, Char) = list(1)
    if (first._1 == second._2 && first._2 == second._1) return true else return false
  }
}
```
