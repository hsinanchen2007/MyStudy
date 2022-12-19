```scala
object Solution {
  def primePalindrome(N: Int): Int = {
    if (N <= 2) return 2
    var i = N - (N & 0x1) + 1
    while (true) {
      if (reverse(i) == i && isPrime(i)) return i
      i += 2
      if (i >= 10000000) return 100030001
    }
    -1
  }

  def reverse(N: Int): Int = {
    var res = 0
    var n = N
    while (n > 0) {
      res = res * 10 + n % 10
      n /= 10
    }
    res
  }

  def isPrime(N: Int): Boolean = {
    if (N < 2) return false
    if (N == 2) return true
    (2 to (math.sqrt(N) + 0.5).toInt).foreach(i => if (N % i == 0) return false)
    true
  }
}
```
