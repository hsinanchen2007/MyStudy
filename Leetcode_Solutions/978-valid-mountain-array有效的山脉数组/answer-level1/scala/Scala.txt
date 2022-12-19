### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def validMountainArray(A: Array[Int]): Boolean = {
    if (A.length < 3) return false
    var i = 0
    while (i < A.length - 1 && A(i) < A(i + 1)) {
      i += 1
    }
    if (i == 0 || i == A.length - 1) return false
    while (i < A.length - 1 && A(i) > A(i + 1)) {
      i += 1
    }
    i == A.length - 1    
    }
}
```