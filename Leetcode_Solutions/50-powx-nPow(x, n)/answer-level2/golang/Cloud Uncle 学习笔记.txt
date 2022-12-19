1.位运算
```
func myPow(x float64, n int) float64 {
    if n < 0 {
        x = 1 / x
        n = -n
    }

    pow := float64(1)
    for n != 0 {
        //奇数情况，需要将结果乘以x
        if n&1 == 1 {
            pow *= x
        }
        //偶数情况，需要将x自乘
        x *= x
        //位移一位，n=n/2
        n >>= 1
    }

    return pow
}
```
2.分治
```
func myPow(x float64, n int) float64 {
    //terminator
    if n == 0 {
        return 1        
    }
    if n < 0 {
        x = 1/x
        n = -n
    }
    
    //process logic of current level(split big problem)
    //drill down(subproblems)
    res := myPow(x, n/2)
    //merge(subsult)
    if n%2 != 0 {
        res = res * res * x
    } else {
        res = res * res
    }
    //revert states
    return res
}
```
```
func myPow(x float64, n int) float64 {
    if n == 0 {
        return 1
    }
    //小于0的情况
    if n < 0 {
        return 1 / myPow(x, -n)        
    }
    //n为奇数的情况
    if n%2 != 0 {
        return x * myPow(x, n-1)       
    }
    
    return myPow(x*x, n/2)
}
```
