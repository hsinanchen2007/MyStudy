```scala
object Solution {
  def minSteps(n: Int): Int = {
    var t = n
    var res = 0
    (2 to n).foreach(i => {
      while (t % i == 0) {
        res += i
        t /= i
      }
    })
    res
  }
}
```
