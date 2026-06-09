### 代码

```scala
object Solution {
    def flipAndInvertImage(A: Array[Array[Int]]): Array[Array[Int]] = {
         A.map{_.reverse.map(1 - _)}
    }
}
```