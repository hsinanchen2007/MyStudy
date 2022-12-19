```
object Solution {
  def reverseOnlyLetters(S: String): String = {
    val ret = S.toArray
    var left = 0
    var right = S.length - 1
    while (left < right) {
      while (!S(left).isLetter && left < right) {
        left += 1
      }
      while (!S(right).isLetter && left < right) {
        right -= 1
      }
      if (left < right) {
        val tmp = ret(right)
        ret(right) = ret(left)
        ret(left) = tmp
        left += 1
        right -= 1
      }
    }
    ret.mkString
  }
}
```
