
### 代码

```scala
object Solution {
    def minCostClimbingStairs(cost: Array[Int]): Int = {
        val dp = new Array[Int](cost.length) //建立长度为length的动态规划数组
        dp(0) = cost(0) //初值，根据语法，用（）不是[]
        dp(1) = cost(1)
        for(i <- 2 until cost.length){ //循环，注意to 和until的区别
            dp(i) = math.min(dp(i-1),dp(i-2))+cost(i)
        }
        math.min(dp(cost.length - 1),dp(cost.length -2)) //返回值
        
    }
}
```