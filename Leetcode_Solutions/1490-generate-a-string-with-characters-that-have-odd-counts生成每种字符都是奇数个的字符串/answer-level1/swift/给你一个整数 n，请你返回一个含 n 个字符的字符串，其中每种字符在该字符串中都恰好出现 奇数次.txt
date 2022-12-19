### 解题思路
将整数拆解成多个整数之和，如为偶数即奇数+奇数 如为奇数即为本身即可

### 代码

```swift
class Solution {
    func generateTheString(_ n: Int) -> String {
        if n == 1 {
            return "a"
        }
        if n%2 == 0 {
            var a =  String(repeating: "a", count: n-1)
            a.append("b")
            return a
        } else {
            var a =  String(repeating: "a", count: n-2)
            a.append("b")
            a.append("c")
            return a
        }
    }
}
```

### 代码

```swift

class Solution {
    func generateTheString(_ n: Int) -> String {
        if n == 1 {
            return "a"
        }
        if n%2 == 0 {
            var a =  String(repeating: "a", count: n-1)
            a.append("b")
            return a
        } else {
            return String(repeating: "a", count: n)
        }
    }
}

```