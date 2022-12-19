### 解题思路
直接转换可能会超出类型的限制，所以转换思想对每个位上的指数进行操作

### 代码

```swift
class Solution {
func numSteps(_ s: String) -> Int {
    guard s.count >  1 else { return 0}

    var index: [Int] = []

    for (i, c) in s.reversed().enumerated() {
        let n = Int(String(c)) ?? 0
        if i == 0 && n == 1 {
            index.append(0)
        } else if n == 1 {
            index.append(i)
        }
    }

    var count = 0

    while !index.isEmpty {
        let first = index[0]

        if index.count == 1 && first == 0 {
            break
        }

        if first == 0 {
            if index.count > 1 {
                let second = index[1]
                if second == 0 {
                    index.removeFirst()
                    index[0] = 1
                } else {
                    index[0] = 1
                    count += 1
                }
            }
        } else {
            count += index[0]
            index = index.map({ $0 - index[0]})
        }
    }

    return count
}
}
```