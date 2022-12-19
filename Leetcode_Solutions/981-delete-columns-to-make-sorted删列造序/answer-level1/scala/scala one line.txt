```scala []
object Solution {
    def minDeletionSize(A: Array[String]): Int = {
        A.map(_.toCharArray).transpose.map(_.mkString).count(x => x != x.sorted)
    }
}
```