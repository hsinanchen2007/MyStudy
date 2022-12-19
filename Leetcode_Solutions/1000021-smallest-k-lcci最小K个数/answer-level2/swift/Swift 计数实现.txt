### 解题思路

因为有负数，没有采用桶，还是计数的路子

### 代码

```swift
class Solution {
    func smallestK(_ arr: [Int], _ k: Int) -> [Int] {
        var dict:[Int:Int] = [:]
        var res:[Int] = []

        for i in arr {
            if dict[i] != nil {
                dict[i] = dict[i]! + 1
            } else {
                dict[i] = 1
            }
        }

        for j in dict.keys.sorted() {
            let n = dict[j]!
            if n > 1 {
                for _ in 1...n {
                    if res.count == k {
                        break
                    }
                    res.append(j)
                }
            } else {
                if res.count == k {
                    break
                }
                res.append(j)
            }
        }

        return res
    }
}
```