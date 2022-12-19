```
object Solution {
  def reverseStr(s: String, k: Int): String = {

    var left = 0
    val sArray: Array[Char] = s.toArray

    var flag = true

    while (left <= s.length - 1) {
      var start = left
      var end = if (left + k - 1 < s.length) left + k - 1 else s.length - 1
      if (flag) {
        while (start < end) {
          val tmp = sArray(start)
          sArray(start) = sArray(end)
          sArray(end) = tmp
          start += 1
          end -= 1
        }
      }
      flag = !flag
      left += k
    }
    sArray.mkString
  }
}
```
