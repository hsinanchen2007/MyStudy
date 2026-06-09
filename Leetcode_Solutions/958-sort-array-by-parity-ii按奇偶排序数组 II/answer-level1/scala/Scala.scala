### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def sortArrayByParityII(A: Array[Int]): Array[Int] = {
    val B = new Array[Int](A.length)
    var i = 0
    for (res <- A) {
      if (res % 2 == 0) {
        B(i) = res
        i += 2
      }
    }
      i = 1
      for (res <- A) {
        if (res % 2 == 1) {
          B(i) = res
          i += 2
        }
      }
      B 
    }
}
```