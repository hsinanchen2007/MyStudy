### 解题思路
直接进行两次循环即可。

### 代码

```swift
class Solution {
    func findNumberIn2DArray(_ matrix: [[Int]], _ target: Int) -> Bool {
        // index没有使用，用_代替即可。
        for (_, nums) in matrix.enumerated() {
            for (_, num) in nums.enumerated() {
                if num == target {
                    return true
                }
            }
        }
        return false
    }
}

```