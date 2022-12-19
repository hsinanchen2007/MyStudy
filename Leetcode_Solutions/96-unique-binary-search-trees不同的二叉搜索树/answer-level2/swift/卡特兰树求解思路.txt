### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func numTrees(_ n: Int) -> Int {
        if n <= 1 {
            return 1
        }
        var c = [Int](repeating: 0, count: n + 1)
        c[0] = 1
        c[1] = 1
        for i in 2...n {
            for j in 1...i {
                c[i] += c[j - 1] * c[i - j]
            }
        }
        return c[n]
    }
}
```