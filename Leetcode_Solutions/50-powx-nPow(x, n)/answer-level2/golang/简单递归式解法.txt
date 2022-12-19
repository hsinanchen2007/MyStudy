和一般递归解题思路一致。不过因为go整除不尽的时候其实已经具有舍掉小数的特性（相当于(n-1)/2), 所以递归的时候可以不用写奇数n等于调用n-1再乘x。
```go
func myPow(x float64, n int) float64 {
    if n == 1 {
        return x
    }else if n==0{
        return 1
    }else if n < 0 {
        return 1.0 / myPow(x, -n)
    }else{
        if n % 2 == 0{
            return myPow(x*x, n/2)
        }else{
            return myPow(x*x, n/2) * x      
        }
    }
}
```
