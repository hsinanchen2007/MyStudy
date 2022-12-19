```
class Solution {
    func nthUglyNumber(_ n: Int, _ a: Int, _ b: Int, _ c: Int) -> Int {
        let sorted = [a,b,c].sorted { (x, y) -> Bool in
            return x < y
        }
        var left = max(sorted[0], n)
        var right = n * a
        let ab = (a * b) / gcd(a, b)
        let ac = (a * c) / gcd(a, c)
        let bc = (b * c) / gcd(b, c)
        let abc = (ab * c) / gcd(ab, c)
        while left < right {
            let mid = left + (right - left) / 2
            let numA = mid / a
            let numB = mid / b
            let numC = mid / c
            let numAB = mid / ab
            let numBC = mid / bc
            let numAC = mid / ac
            let numABC = mid / abc
            
            let count = numA + numB + numC - numAB - numAC - numBC + numABC
            if count < n {
                left = mid + 1
            }else {
                right = mid
            }
        }
        return left
    }
    func gcd(_ x: Int, _ y: Int) -> Int {
        if y == 0 {
            return x
        }
        if x < y {
            return gcd(y, x)
        }
        return gcd(y, x % y)
    }
}
```