### 方法： 预先计算每行，每列是否只有1个'B'
按照题意，我们需要遍历矩阵，每次需要计算第i行有几个'B'， 第j行有个‘B’。 为避免重复计算，我们预先统计每一行, 每一列是否只有一个'B'。

```scala []
object Solution {
    def findLonelyPixel(A: Array[Array[Char]]): Int = {
        val n = A.length
        val m = A.head.length
        val row = Array.fill(n)(false)
        val col = Array.fill(m)(false)
        row.indices foreach {i => row(i) = A(i).count(_=='B') == 1}
        col.indices foreach {j => col(j) = A.map(x => x(j)).count(_=='B') == 1}
        var cnt = 0
        for{
            i <- A.indices
            j <- A(i).indices
            if A(i)(j) == 'B'
            if row(i) && col(j)
        } cnt += 1
        cnt
    }
}
```
### 复杂度
1. 时间复杂度： O(N*M)
2. 空间复杂度： O(N+M)