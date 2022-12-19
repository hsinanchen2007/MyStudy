### 解题思路

(逆序数 - 原数) == 0

### 代码

```swift
class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        if x < 0 {
            return false
        }
        var reversed = 0
        var X = x
        while X / 10 != 0 {
            reversed = reversed * 10 + X % 10
            X = X / 10
        }
        if X > 0 {
            reversed = reversed * 10 + X
        }
        return reversed - x == 0
    }
}

```