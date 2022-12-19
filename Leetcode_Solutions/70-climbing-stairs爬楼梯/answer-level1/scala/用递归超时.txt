```
object Solution {
    // def climbStairs(n: Int): Int = {
    //     if(n == 1 || n == 2) n else climbStairs(n - 1) + climbStairs(n - 2)
    // }
    
    def climbStairs(n: Int): Int = {
        if(n == 1 || n == 2) n
        else {
            val res = new Array[Int](n + 1)
            res(1) = 1
            res(2) = 2
            for(i <- 3 to n){
                res(i) = res(i - 1) + res(i - 2)
            }
            res(n)
        }
    }
}
```
