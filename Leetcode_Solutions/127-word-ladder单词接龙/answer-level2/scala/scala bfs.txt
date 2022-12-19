```scala
import scala.collection.mutable

object Solution {
  def ladderLength(beginWord: String, endWord: String, wordList: List[String]): Int = {
    val s = new mutable.HashSet[String]()
    wordList.foreach(i => s.add(i))
    val q = new mutable.Queue[String]()
    q.enqueue(beginWord)
    var res = 0
    while (q.nonEmpty) {
      (q.length until 0 by -1).foreach(_ => {
        val word = q.front
        q.dequeue
        if (word == endWord) return res + 1
        word.indices.foreach(j => {
          val newWord = new mutable.StringBuilder
          newWord.append(word)
          ('a' to 'z').foreach(ch => {
            newWord(j) = ch
            if (s.contains(newWord.toString) && newWord.toString != word) {
              q.enqueue(newWord.toString)
              s.remove(newWord.toString)
            }
          })
        })
      })
      res += 1
    }
    0
  }
}
```
