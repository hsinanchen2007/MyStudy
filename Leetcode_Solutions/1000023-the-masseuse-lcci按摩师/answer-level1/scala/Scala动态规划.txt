```scala
import scala.math.max
object Solution {
    def massage(nums: Array[Int]): Int = {
        var dp = new Array[Int](nums.length+2)
        for (i <- 2 until dp.length){
            dp(i) = max(dp(i-1),dp(i-2)+nums(i-2))
        }
        dp(dp.length-1)
    }
}
```
