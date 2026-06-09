```
class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
        if n == 0 {
            return 1
        }
        var x = x
        var n = n
        if n < 0 {
            return myPow(1 / x, -n)
        }
        while n > 0 {
            if n & 1 == 1 {
                return x * myPow(x, n - 1)
            }   
            x = x * x
            n >>= 1
        }
        return x
    }
}
```