```scala
object Solution {
  def longestPalindrome(s: String): Int = {
    val cnt = new Array[Int](128)
    var res = 0
    s.toCharArray.foreach(i => cnt(i) += 1)
    cnt.foreach(i => {
      res += i / 2 * 2
      if (i % 2 == 1 && res % 2 == 0) res += 1
    })
    res
  }
}
```
