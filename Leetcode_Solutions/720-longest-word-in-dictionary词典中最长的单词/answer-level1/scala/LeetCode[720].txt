```
object Solution {
  def allExt(mymap: scala.collection.mutable.Map[String, Int], str: String): Boolean = {
    (1 to str.size - 1).forall(x => mymap.contains(str.slice(0, x)))
  }

  def longestWord(words: Array[String]): String = {
    var maxString = ""
    val mymap = scala.collection.mutable.Map[String, Int]()
    for (item <- words) {
      mymap(item) = item.length
    }
    for (item <- mymap) {
      val (str, length) = item
      if (allExt(mymap, str)) {
        if (str.length > maxString.length) maxString = str
        else if (str.length == maxString.length) {
          if (str <= maxString) {
            maxString = str
          }
        }
      }
    }
    return maxString
  }
}

```
