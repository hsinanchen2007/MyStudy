第一次用scala写算法题，这么多for循环是不是有点low了...

```scala
object Solution {

    def minimumTotal(triangle: List[List[Int]]): Int = {
        val n = triangle.size
        val memo = new Array[Array[Int]](n)

        for (i <- 1 to n)
            memo(i-1) = Array.fill(i)(-1)

        for (i <- 0 until n)
            memo(n-1)(i) = triangle(n-1)(i)

        for (i <- n-2 to 0 by -1)
            for (j <- 0 to i) {
                val cur = triangle(i)(j)
                val left = memo(i+1)(j)
                val right = memo(i+1)(j+1)
                memo(i)(j) =
                    if (left < right)
                        cur + left
                    else
                        cur + right
            }
        memo(0)(0)
    }
    
}
```
