```scala []
object Solution {
    // sort
    // dp[j] = 1 max max(dp[i]+ 1), for i that A(j) % A(i) == 0
    
    def largestDivisibleSubset(nums: Array[Int]): List[Int] = {
        if(nums.length == 0) return Nil
        val A = nums.sorted
        val n = A.length
        val dp = Array.fill(n)(List.empty[Int])
        for{i <- 0 until n}{
            dp(i) = A(i)::Nil
            for{
                j <- 0 until i 
                if A(i) % A(j) == 0
            }{
                if(dp(j).length + 1 > dp(i).length)
                    dp(i) = A(i)::dp(j)
            }
        }
        dp.sortBy{x=> - x.length}.head.reverse
    }
}
```
