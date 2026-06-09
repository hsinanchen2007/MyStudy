```
object Solution {
  def largeGroupPositions(S: String): List[List[Int]] = {
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[List[Int]]()
    var start = 0
    var end = 0
    var num = 0
    while (start < S.length) {
      end = start + 1
      while (end < S.length && S(end) == S(start)) {
        end += 1
      }
      if (end - start >= 3) myArrayBuffer += List(start, end - 1)
      start = end
    }

    myArrayBuffer.toList
  }
```
