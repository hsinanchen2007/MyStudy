```Scala
object Solution {
  def isPalindrome(x: Int): Boolean = {
    @scala.annotation.tailrec
    def converse(x: Int, y: Int): Int = {
      if (x / 10 == 0) x % 10 + y
      else converse(x / 10, (y + x % 10) * 10)
    }

    if (x < 0) false
    else if (x == 0) true
    else if (x % 10 == 0) false
    else converse(x, 0) == x
  }
}
```
