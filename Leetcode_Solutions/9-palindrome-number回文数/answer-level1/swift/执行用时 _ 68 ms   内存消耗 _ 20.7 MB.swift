### 解题思路
1. 负数不符合要求
2. 反转数组生成新的数字

### 代码

```swift
class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        if x < 0 {
            return false
        }
        var X = x
        var reverse = 0
        while X >= 10 {
            reverse = reverse*10 + X%10
            X /= 10
        }
        reverse = reverse*10 + X%10
        return x == reverse
    }
}
```