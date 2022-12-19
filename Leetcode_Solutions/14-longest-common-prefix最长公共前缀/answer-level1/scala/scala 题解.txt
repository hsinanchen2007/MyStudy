```scala
object Solution {
  def longestCommonPrefix(strs: Array[String]): String = {
    if (strs.length == 0) return ""
    if (strs.length == 1) strs(0)
    for (i <- 0 until strs(0).length)
      for (j <- 1 until strs.length)
        if ((i >= strs(j).length) || strs(j)(i) != strs(0)(i))
          return strs(0).substring(0, i)
    strs(0)
  }
}
```
