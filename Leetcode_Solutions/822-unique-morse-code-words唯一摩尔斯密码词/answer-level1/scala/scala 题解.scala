```scala
object Solution {
  private val morse = Array(".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..")

  def uniqueMorseRepresentations(words: Array[String]): Int = words.map(_.map(x => morse(x - 'a')).reduceLeft(_ + _)).distinct.length
}
```
