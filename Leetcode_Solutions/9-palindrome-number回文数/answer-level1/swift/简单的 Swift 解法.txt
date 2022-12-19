### 解题思路

1. 转换成 string，从前(i)和后(j)同时往中间遍历，s[i]!=s[j] 就说明不是回文数 (104ms)
2. 通过公式推导(48ms)

如果是回文数从后往前遍历，同时做一遍运算最后的结果应该和原来的数一样

// 121
// 121 % 10 = 1
// 0*10 + 1 = 1
// 1*10 + 2 = 12
// 12*10 + 1 = 121
// sum * 10 + d

### 代码

```swift
class Solution {

    func isPalindrome(_ x: Int) -> Bool {
    var s = String(x)

    while s.count > 1 {
        if s.first != s.last {
            return false
        }

        s.removeLast()
        s.removeFirst()
    }

    return true
}

    func isPalindrome(_ x: Int) -> Bool {
     var num = x
     var sum = 0
     while num > 0 {
        let d = num % 10
        sum = sum * 10 + d
        num /= 10
     }

     return sum == x
    }
}
```