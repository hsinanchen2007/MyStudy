```go
/**
分治法（递归）
时间复杂度：O(log n)
空间复杂度：O(log n)
*/
func myPow2(x float64, n int) float64 {
    if n == 0 {
        return 1
    }
    if n < 0 {
        return 1 / myPow(x, -n)
    }
    if n % 2 != 0 {
        return x * myPow(x, n-1)
    }

    return myPow(x*x, n/2)
}
```