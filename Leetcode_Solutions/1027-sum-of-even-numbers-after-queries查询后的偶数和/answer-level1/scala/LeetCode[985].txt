```
object Solution {

  def isEven(in: Int): Boolean = {
    in % 2 == 0
  }

  def sumEvenAfterQueries(A: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
    var initSum = A.filter(_ % 2 == 0).sum
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[Int]()
    for (item <- queries) {
      val value = item(0)
      val index = item(1)
      if (isEven(value)) {
        if (isEven(A(index) + value)) {
          initSum += value
        }
      } else {
        if (isEven(A(index) + value)) {
          initSum += A(index)
          initSum += value
        } else {
          initSum -= A(index)
        }
      }
      A(index) += value
      myArrayBuffer += initSum
    }
    myArrayBuffer.toArray
  }
}

```
