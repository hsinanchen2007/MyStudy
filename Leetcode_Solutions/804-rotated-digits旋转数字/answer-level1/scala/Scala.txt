### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def rotatedDigits(N: Int): Int = {
    var ans = 0
    for (n <- 1 to N)
      if (good(n, false))
        ans += 1
    ans
  }

  def good(n: Int, flag: Boolean): Boolean = {
    if (n == 0) return flag
    val d = n % 10;
    if (d == 3 || d == 4 || d == 7)
      return false
    if (d == 0 || d == 1 || d == 8)
      return good(n / 10, flag)
    good(n / 10, flag = true)    
    }
}
```