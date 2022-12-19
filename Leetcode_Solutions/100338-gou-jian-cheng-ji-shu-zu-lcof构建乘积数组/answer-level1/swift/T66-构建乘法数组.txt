### 解题思路
如果直接使用暴力两次循环，会超时。所以只能使用更简单的方法，就是对称相乘。

### 代码

```swift
class Solution {
    func constructArr(_ a: [Int]) -> [Int] {
        // 创建初始的结果数组
        var result = Array.init(repeating: 1, count: a.count)

        var left = 1
        for i in 0..<a.count {
            result[i] = left
            left *= a[i]
        }

        var right = 1
        for i in (0..<a.count).reversed() {
            result[i] *= right
            right *= a[i]
        }

        return result
    }
}
```