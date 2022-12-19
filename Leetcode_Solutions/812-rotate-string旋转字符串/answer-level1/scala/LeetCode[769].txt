```
object Solution {
  def rotateString(A: String, B: String): Boolean = {
    if(A.length != B.length) return false
    val mymap = scala.collection.mutable.Map[(Char, Char), Int]()
    for (i <- 0 to A.length - 1) {
      val start = i
      val end = (i + 1) % A.length
      val PairA = (A(start), A(end))
      val PairB = (B(start), B(end))
      if (mymap.contains(PairA)) mymap(PairA) += 1
      else mymap(PairA) = 1
      if (mymap.contains(PairB)) mymap(PairB) -= 1
      else mymap(PairB) = -1
    }
    mymap.forall(x => x._2 == 0)
  }
}
```
