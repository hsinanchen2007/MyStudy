### 解题思路
字符是一个长度为8的数据类型，因此总共有可能256种可能。
每个字母根据其ASCII码值作为数组下标对应数组的一个数字。
数组中存储的是每个字符的出现次数。
注意：第二次循环要以原字符串顺序，不能以存储的数组做遍历。
### 代码

```swift
class Solution {
    func firstUniqChar(_ s: String) -> Character {
        var target: Character = " "
        // 第一次遍历，先把字符串每个字母出现次数，存到256的数组
        var arr = Array(0..<256).map { _ in return 0}
        for c in s {
            if let ascii = c.asciiValue {
                let idx = Int(ascii)
                arr[idx] += 1
            }
        }
        
        // 从头遍历存储的数组，找到第一个为1的字符
        for c in s {
            if let ascii = c.asciiValue {
                let idx = Int(ascii)
                if arr[idx] == 1 {
                    target = c
                    break
                }
            }
        }
        return target


    }
}
```