### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def canThreePartsEqualSum(A: Array[Int]): Boolean = {
    if (A.sum % 3 != 0) return false
    val avg = A.sum / 3
    var i = 0
    var res1 = 0
    var res2 = 0
    
    while (i < A.length) {
      res1 += A(i)
      if (res1 == avg) {
          var j = i + 1
        while (j < A.length - 1) {
          res2 += A(j)
          if (res2 == avg) {
            return true
          }
          j += 1
        }
      }
      i += 1
    }
    false
    }
}
```