### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    import scala.collection.mutable
    def uniqueMorseRepresentations(words: Array[String]): Int = {
    val map: Array[String] =
      Array(".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..")
    if (words == null) return 0
    val set = new mutable.HashSet[String]()
    for (s <- words) {
      val sb = new StringBuilder
      for (c <- s.toCharArray) {
        sb.append(map(c - 'a'))
      }
      set.add(sb.toString)
    }
    set.size    
    }
}
```