```
object Solution {
  def makeNewWord(s: String, num: Int) = {
    val ret = if (List('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').contains(s(0))) s
    else s.slice(1, s.length) + s(0)
    ret + "m" + "a" * (num + 2)
  }

  def toGoatLatin(S: String): String = {
    val words = S.split(" ")
    words.zipWithIndex.map(x => makeNewWord(x._1, x._2)).mkString(" ")
  }
}
```
