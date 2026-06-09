### 解题思路
1.求解数列的一阶差分；
2.差分数列全部大于0或者全部小于0为True

### 代码

```scala
object Solution {
    def isMonotonic(A: Array[Int]): Boolean = {
        val size = A.length - 1
        val A_diff:Array[Int] = new Array[Int](size)
        for(i <- 0 until A.length - 1){
        A_diff(i) = A(i+1) - A(i)
        }

        A_diff.map(x => if(x >= 0) 1 else 0).sum == size |
        A_diff.map(x => if(x <= 0) 1 else 0).sum == size
    }
}
```