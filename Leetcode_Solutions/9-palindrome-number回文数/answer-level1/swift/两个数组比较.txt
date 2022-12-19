### 解题思路
一个正向数组，一个反向数组，比较

### 代码

```swift
class Solution {
    func isPalindrome(_ x: Int) -> Bool {
    if x < 0 {
        return false
    }
    ///两端向中间，执行与操作
    let string = String(x)
    let arr0 =  string.map {
        $0
    }
    let arr1 = arr0.reduce([],{ [$1] + $0 })
    for i in 0..<arr0.count {
        if arr0[i] != arr1[i] {
            return false
        }
    }
    return true
}
}
```