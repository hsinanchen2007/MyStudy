### 解题思路
因为数据有一个固定的范围，而且不需要顺序和步骤，只需要将所有的年龄哈希到一个121长度的数组，然后穷举这个121长度的数组即可

### 代码

```swift
class Solution {
    func numFriendRequests(_ ages: [Int]) -> Int {
        var count = 0
        /// 1 <= ages[i] <= 120.
        /// 将年龄hash到一个数字，用下标记录年龄，内容记录年龄出现的次数
        var ageCounts = Array(repeating: 0, count: 121)
        ages.forEach { (age) in
            var tmpCount = ageCounts[age]
            tmpCount += 1
            ageCounts[age] = tmpCount
        }
        
        for A in 1...120 {
            for B in 1...120 {
                if B <= A / 2 + 7 || A < B || (B > 100 && A < 100) {
                    continue
                } else {
                    let a = ageCounts[A]
                    let b = ageCounts[B]
                    if a > 0, b > 0 {
                        count += a * b
                        /// 先假定所有人都可以给自己发，然后减去给自己发的
                        if A == B {
                            count -= a
                        }
                    }
                }
            }
        }
        return count
    }
}
```