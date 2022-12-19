```
class Solution {
    func fourSumCount(_ A: [Int], _ B: [Int], _ C: [Int], _ D: [Int]) -> Int {
        var tmp: [Int: Int] = [:]
        for a in A {
            for b in B {
                let sum = a + b
                if let val = tmp[sum] {
                    tmp[sum] = val + 1
                }else{
                    tmp[sum] = 1
                }
            }
        }
        var res = 0
        for c in C {
            for d in D {
                let sum = c + d
                if let val = tmp[-sum] {
                    res += val
                }
            }
        }
        
        return res
    }
}
```