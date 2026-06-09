```
object Solution {
  def sortedSquares(A: Array[Int]): Array[Int] = {
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[Int]()
    val (a, b) = A.partition(_ < 0)
    val ints0: Array[Int] = a.reverse.map(x => x * x)
    val ints1: Array[Int] = b.map(x => x * x)
    var i = 0
    var j = 0
    while (i < ints0.length && j < ints1.length) {
      if (ints0(i) < ints1(j)) {
        myArrayBuffer += ints0(i)
        i += 1
      } else {
        myArrayBuffer += ints1(j)
        j += 1
      }
    }

    while (i < ints0.length) {
      myArrayBuffer += ints0(i)
      i += 1
    }
    while (j < ints1.length) {
      myArrayBuffer += ints1(j)
      j += 1
    }
    return myArrayBuffer.toArray
  }
}
```
