### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func divisorGame(_ N: Int) -> Bool {
        var n = N
        var count = 0
        var over = false
        var isFind = false
        while(!over) {
            for x in 1...n {
                if n%x == 0 && x != n{
                    isFind = true
                    n = n-x
                    count += 1
                    break
                }
            }
            if !isFind {
                over = true
            }
            isFind = false
        }
        return count%2 == 1 ? true:false
    }
}
```