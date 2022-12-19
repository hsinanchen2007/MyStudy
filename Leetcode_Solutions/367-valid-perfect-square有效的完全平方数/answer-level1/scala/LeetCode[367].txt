```
object Solution {
  def isPerfectSquare(num: Int): Boolean = {
    if (num < 2) return true
    var start = 2
    var end: Int = num / 2
    while (start <= end) {
      val i: Int = start + (end - start) / 2
//      print(start,end,i)
      if (num % i == 0 && i == num / i) return true
      else if (i  > num / i)  {
//        println(">")
        end = i - 1
      } else {
//        println("<")
        start = i + 1
      }
    }
    false
  }
}

```
