```
object Solution {
  def minDeletionSize(A: Array[String]): Int = {
    (0 until A(0).length).map(i => {
      (i, A.map(s => s(i)).toList.sliding(2, 1).forall(x => x(1) >= x(0)))
    }).toList.count((!_._2))
  }
}
```
