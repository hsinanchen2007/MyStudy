```
object Solution {
  def getSum(a: Int, b: Int): Int = {
    if (b == 0) return a
    else getSum(a ^ b, (a & b) << 1)
  }
}
```
