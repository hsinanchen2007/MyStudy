```scala []
object Solution {
    
    // f(0, n-1) : max gain 
    // f(0, n-1) = (rest - f(0,n-2)) max (rest - f(1, n-1))
    // f(0, n-1) = rest - (f(0,n-2) min f(1,n-1))
    def PredictTheWinner(A: Array[Int]): Boolean = {
        val n = A.length
        if(n % 2 == 0) return true
        val dp = Array.fill(n,n)(0)
        A.indices foreach {i => dp(i)(i) = A(i)}
        A.indices foreach {i => if(i+1 < n) dp(i)(i+1) = A(i) max A(i+1)}
        for{
            k <- 2 to n-1
            i <- 0 until n
            if i +k < n
        }{
            dp(i)(i+k) = A.slice(i,i+k+1).sum - (dp(i+1)(i+k) min dp(i)(i+k-1))
        }
        dp(0)(n-1) *2 >= A.sum
    }
}
```
