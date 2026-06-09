```
  def isIsomorphic(s: String, t: String): Boolean = {
    val mymap = scala.collection.mutable.Map[Char, Char]()
    val length: Int = s.length
    for (i <- 0 until length) {
      if (mymap.contains(s(i))) {
        if (mymap(s(i)) != t(i)) {
          return false
        }
      } else {
        if (mymap.values.toList.contains(t(i))) return false
        else mymap(s(i)) = t(i)
      }
    }
```



