### 解题思路

一次遍历获取数量
再次遍历直接返回

### 代码

```swift
class Solution {
    func firstUniqChar(_ s: String) -> Character {
        var dict = [Character:Int]()
        for i in s {
            if let v = dict[i] {
                dict[i] = v + 1
            } else {
                dict[i] = 1
            }
        }
        for i in s {
            if let v = dict[i] {
                if v == 1 {
                    return i
                }
            }
        }
        return " "
    }
}
```