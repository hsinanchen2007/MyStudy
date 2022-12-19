```
object Solution {
    def flipAndInvertImage(A: Array[Array[Int]]): Array[Array[Int]] = {
        A.map((x: Array[Int]) => x.reverse.map(1-(_: Int)))
    }
}
```
