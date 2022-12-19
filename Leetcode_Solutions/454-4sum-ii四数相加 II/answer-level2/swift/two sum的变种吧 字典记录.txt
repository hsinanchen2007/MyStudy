a+b+c+d=0 => a+b = -(c+d)
所以分别遍历 ab 和 cd
```
class Solution {
    func fourSumCount(_ A: [Int], _ B: [Int], _ C: [Int], _ D: [Int]) -> Int {
        // a + b + c + d = 0 => a + b = - (c + d)
        var res = 0
        let len = A.count
        var dic = [Int: Int]()
        for i in 0 ..< len {
            for j in 0 ..< len {
                let sum = A[i] + B[j]
                dic[-sum, default: 0] += 1
            }
        }

        for i in 0 ..< len {
            for j in 0 ..< len {
                let sum = C[i] + D[j]
                if let cnt = dic[sum] {
                    res += cnt
                }
            }
        }

        return res
    }
}
```