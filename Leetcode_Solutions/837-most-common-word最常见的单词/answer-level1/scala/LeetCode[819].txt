```
object Solution {
  def mostCommonWord(paragraph: String, banned: Array[String]): String = {
    val mymap = scala.collection.mutable.Map[String, Int]()
    val words: Array[String] = paragraph.split("\\W").filter(_ != "")
    for (item <- words) {
      val lowCase: String = item.toLowerCase
      if (!banned.contains(lowCase) && item != " ") {
        if (mymap.contains(lowCase)) {
          mymap(lowCase) += 1
        } else {
          mymap(lowCase) = 1
        }
      }
    }
    val tuple: (String, Int) = mymap.maxBy((_: (String, Int))._2)
    tuple._1
  }
}
```
