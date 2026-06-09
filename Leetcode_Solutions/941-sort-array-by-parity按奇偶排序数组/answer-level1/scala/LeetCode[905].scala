```
object Solution {
  def sortArrayByParity(A: Array[Int]): Array[Int] = {
    val (a, b) = A.partition(x => x % 2 == 0)
    a ++ b
  }
}
```
