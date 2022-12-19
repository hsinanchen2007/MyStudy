不过脑子的暴力

```swift
class Solution {
    func numsSameConsecDiff(_ N: Int, _ K: Int) -> [Int] {
        if N == 1 {
            return [0,1,2,3,4,5,6,7,8,9]
        }
        var param = 1
        for _ in 2...N {
            param *= 10
        }
        var res = [Int]()
        for i in 1...9 {
            eachNum(K, i, 0, param, &res)
        }
        
        return res
    }
    
    func eachNum(_ k: Int, _ prev: Int, _ total: Int, _ n: Int, _ res: inout [Int]) {
        if prev >= 0 && prev <= 9 && n >= 1 {
            let c = prev * n + total
            if n == 1 {
                if !res.contains(c) {
                    res.append(c)
                }
            }else{
                eachNum(k, k + prev, c, n/10, &res)
                eachNum(k, prev - k, c, n/10, &res)
            }
        }
    }
}
```