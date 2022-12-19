```scala
object Solution {
  def reorganizeString(S: String): String = {
    var idx = 1
    val s = new StringBuilder
    s.append(S)
    val cnt = Array.fill(26)(0)
    s.foreach(i => cnt(i - 'a') += 100)
    (0 until 26).foreach(i => cnt(i) += i)
    util.Sorting.quickSort(cnt)
    cnt.foreach(i => {
      val t = i / 100
      val ch: Char = ('a' + (i % 100).toChar).toChar
      if (t > (s.length + 1) / 2) return ""
      (0 until t).foreach(_ => {
        if (idx >= s.length) idx = 0
        s(idx) = ch
        idx += 2
      })
    })
    s.toString
  }
}
```
