### 解题思路


### 代码

```scala
object Solution {
    def heightChecker(heights: Array[Int]): Int = {
    val A = heights.sorted
    var count = 0
    for (i <- A.indices) {
      if (A(i) != heights(i))
        count += 1
    }
    count    
    }
}
```