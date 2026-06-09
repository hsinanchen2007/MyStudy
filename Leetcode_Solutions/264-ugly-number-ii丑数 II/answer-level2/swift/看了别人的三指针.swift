本来自己的暴力解法超时了，看了别人的三指针才知道比较好的这个解法
```swift
class Solution {
    func nthUglyNumber(_ n: Int) -> Int {
        var res = [1]
        var r2 = 0
        var r3 = 0
        var r5 = 0
        while res.count < n {
            let v2 = res[r2] * 2
            let v3 = res[r3] * 3
            let v5 = res[r5] * 5
            let mi = min(min(v2, v3), v5)
            if v2 == mi {
                r2 += 1
            }
            if v3 == mi {
                r3 += 1
            }
            if v5 == mi {
                r5 += 1
            }
            res.append(mi)
        }
        return res[n - 1]
    }
}
```