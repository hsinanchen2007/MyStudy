```scala
object Solution {
  def sortArrayByParity(A: Array[Int]): Array[Int] = {
    var pLeft = 0
    var pRight = A.length - 1
    while (pLeft < pRight) {
      if (A(pLeft) % 2 == 0) pLeft += 1
      else {
        A(pLeft) = A(pLeft) ^ A(pRight)
        A(pRight) = A(pLeft) ^ A(pRight)
        A(pLeft) = A(pLeft) ^ A(pRight)
        pRight -= 1
      }
    }
    A
  }
}
```
