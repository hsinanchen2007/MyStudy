### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def smallestRangeI(A: Array[Int], K: Int): Int = {
    val B = A.sorted
    B(0) += K
    B(B.length - 1) -= K
    if (B(B.length - 1) - B(0) <= 0)
       0
    else
      B(B.length - 1) - B(0)
    }
}
```