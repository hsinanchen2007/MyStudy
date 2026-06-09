### 解题思路

我们只用统计偶数字符出现的次数（需要整数除2，计算多次），如果有奇数字符，不管有多少个，只计算一次即可

### 代码

```swift
class Solution {
    func longestPalindrome(_ s: String) -> Int {
        var ch = Array(repeating: 0, count: 128)
        for i in s {
            ch[Int(i.asciiValue!)] += 1;
        }
        var res = 0
        var first = 0
        for (_,v) in ch.enumerated() {
            if v == 1 && first == 0 {
                res += 1
                first = 1
            }
            if v > 1 {
                if v % 2 != 0 && first == 0 {
                    res += 1
                    first = 1
                }
                res += (v / 2) * 2
            }
        }
        return res
    }
}
```