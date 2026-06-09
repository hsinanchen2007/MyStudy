```scala
object Solution {
  def buddyStrings(A: String, B: String): Boolean = {
    if (A.length != B.length || A.length == 0) return false
    if (A.equals(B)) {
      val gp = A.toCharArray.map((_, 1)).groupBy(_._1)
      gp.map(g => g._2.length).max > 1
    } else {
      var f1 = -1
      var f2 = -1
      A.indices.withFilter(i =>
        A(i) != B(i)).foreach(i =>
        if (f1 == -1) f1 = i
        else if (f1 != -1 && f2 == -1) f2 = i
        else return false)
      f2 != -1 && A(f1) == B(f2) && A(f2) == B(f1)
    }
  }
}
```
