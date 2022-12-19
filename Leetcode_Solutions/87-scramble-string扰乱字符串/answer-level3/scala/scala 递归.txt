```scala
object Solution {
  def isScramble(s1: String, s2: String): Boolean = {
    if (s1 == s2) return true
    if (s1.length != s2.length) return false
    val m = Array.fill(26)(0)
    s1.indices.foreach(i => {
      m(s1(i) - 'a') += 1
      m(s2(i) - 'a') -= 1
    })
    (0 until 26).foreach(i => if (m(i) != 0) return false)
    (1 until s1.length).foreach(i => if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i)) || (isScramble(s1.substring(0, i), s2.substring(s1.length - i)) && isScramble(s1.substring(i), s2.substring(0, s1.length - i)))) return true)
    false
  }
}
```
