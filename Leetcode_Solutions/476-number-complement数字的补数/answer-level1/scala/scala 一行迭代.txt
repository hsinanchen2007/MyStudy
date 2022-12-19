```scala
object Solution {
  def findComplement(num: Int): Int = (1 - num % 2) + 2 * (if (num <= 1) 0 else findComplement(num / 2))
}
```
