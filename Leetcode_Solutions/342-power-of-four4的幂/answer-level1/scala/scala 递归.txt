```scala
object Solution {
  def isPowerOfFour(num: Int): Boolean = {
    num > 0 && (num == 1 || isPowerOfFour(num / 4) && num % 4 == 0)
  }
}
```
