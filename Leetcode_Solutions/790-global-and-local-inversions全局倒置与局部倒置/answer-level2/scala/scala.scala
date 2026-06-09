```scala
object Solution {
  def isIdealPermutation(A: Array[Int]): Boolean = {
    A.indices.foreach(i => if ((A(i) - i).abs > 1) return false)
    true
  }
}
```