```
object Solution {
  def reverse(x: Int): Int = {
    var xs = x
    var res: Long = 0
    var flag: Long = 1
    if(xs<0) {
      xs = -xs
      flag = -1
    }
    while (xs > 0) {
      res = res * 10 + xs % 10
      xs = xs / 10
    }
    res = res*flag
    if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) {
      res = 0
    }
    res.toInt
  }
}
```
