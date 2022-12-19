```
object Solution {
  def letterCasePermutation(S: String): List[String] = {
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[String]()
    import scala.collection.mutable.Queue
    val myqueue = new Queue[String]()
    myqueue.enqueue("")
    for (item <- S) {
      val strings = myqueue.dequeueAll(_ => true)
      val tmp = if (item.isLetter) {
        strings.map(x => x + item.toLower) ++ strings.map(x => x + item.toUpper)
      } else {
        strings.map(x => x + item)
      }
      tmp.foreach(x => myqueue.enqueue(x))
    }
    myqueue.toList
  }
}

```
