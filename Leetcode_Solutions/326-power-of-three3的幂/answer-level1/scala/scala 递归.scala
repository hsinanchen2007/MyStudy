```scala
object Solution {
  @scala.annotation.tailrec
  def isPowerOfThree(n: Int): Boolean = {
    n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)))
  }
}
```
