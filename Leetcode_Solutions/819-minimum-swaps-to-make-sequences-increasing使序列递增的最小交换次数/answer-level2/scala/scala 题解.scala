```scala
object Solution {
  def minSwap(A: Array[Int], B: Array[Int]): Int = {
    var n1 = 0
    var s1 = 1
    (1 until A.length).foreach(i => {
      var n2 = Int.MaxValue
      var s2 = Int.MaxValue
      if (A(i - 1) < A(i) && B(i - 1) < B(i)) {
        n2 = n2.min(n1)
        s2 = s2.min(s1 + 1)
      }
      if (A(i - 1) < B(i) && B(i - 1) < A(i)) {
        n2 = n2.min(s1)
        s2 = s2.min(n1 + 1)
      }
      n1 = n2
      s1 = s2
    })
    n1.min(s1)
  }
}
```
