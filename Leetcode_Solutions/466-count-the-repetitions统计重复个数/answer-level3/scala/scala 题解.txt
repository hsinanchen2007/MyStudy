```scala
object Solution {
  def getMaxRepetitions(s1: String, n1: Int, s2: String, n2: Int): Int = {
    val repeatCnt = new Array[Int](n1 + 1)
    val nextIdx = new Array[Int](n1 + 1)
    var p = 0
    var cnt = 0
    (1 to n1).foreach(i => {
      s1.indices.foreach(j => {
        if (s1(j) == s2(p)) {
          p += 1
          if (p == s2.length) {
            p = 0
            cnt += 1
          }
        }
      })
      repeatCnt(i) = cnt
      nextIdx(i) = p
      (0 until i).foreach(k => {
        if (nextIdx(k) == p) {
          val interval = i - k
          val repeat = (n1 - k) / interval
          val patternCnt = (repeatCnt(i) - repeatCnt(k)) * repeat
          val remainCnt = repeatCnt(k + (n1 - k) % interval)
          return (patternCnt + remainCnt) / n2
        }
      })
    })
    repeatCnt(n1) / n2
  }
}
```
