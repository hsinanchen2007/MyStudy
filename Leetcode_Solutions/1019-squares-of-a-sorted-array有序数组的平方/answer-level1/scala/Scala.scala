### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def sortedSquares(A: Array[Int]): Array[Int] = {
    import scala.collection.mutable.ArrayBuffer
    val B = ArrayBuffer[Int]()
    for (res <- A) {
      B.append(square(res))
    }
    B.sorted.toArray
    }
    def square(int: Int): Int = {
        int * int
  }   
     
}
```