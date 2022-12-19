```
代码块
```
```
object Solution {
  def countSegments(s: String): Int = {

    var num = 0
    var i = 0
    while (i < s.length) {
      if (s(i) != ' ') {
        num += 1
        do {
          i += 1
        } while (i < s.length && s(i) != ' ')
      }
      i += 1
    }
    return num
  }
}
```
