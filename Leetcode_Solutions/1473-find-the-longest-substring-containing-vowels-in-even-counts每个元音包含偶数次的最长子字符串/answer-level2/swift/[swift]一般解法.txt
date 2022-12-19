### 解题思路

1. 因为关注的是元音字母出现次数的奇偶性，因此每个元音字母的统计结果非0即1，所以可能出现共 2^5 = 32种统计结果。
2. 当下标为i和j的位置统计结果相同时，说明从下标i+1到j之间的子串满足要求，长度为 j - i
3. 可以使用位运算代替数组做统计。

### 代码
```swift
 class Solution {
       private let map: [Character:Int] = ["a":0,"e": 1,"i":2,"o":3,"u":4]
    func findTheLongestSubstring(_ s: String) -> Int {
        var maxLength = 0
        var firstIndexOfCounter = [[Int]:Int]()
        var counter = Array<Int>(repeating: 0, count: 5)
        firstIndexOfCounter[[0,0,0,0,0]] = -1
        var i = 0
        for ch in s {
            
            if let index = map[ch] {
                counter[index] = (counter[index] + 1) % 2
            }
            if let first =  firstIndexOfCounter[counter] {
                maxLength = max(maxLength, i - first)
            } else {
                firstIndexOfCounter[counter] = i
            }
            i += 1
        }
        return maxLength
    }
 }
```

```swift
class Solution {
    private let map: [Character:Int] = ["a":0,"e": 1,"i":2,"o":3,"u":4]
    func findTheLongestSubstring(_ s: String) -> Int {
        var maxLength = 0
        var firstIndexOfCounter = [Int8:Int]()
        var counter: Int8 = 0
        firstIndexOfCounter[0] = -1
        var i = 0
        for ch in s {
            
            if let index = map[ch] {
                counter ^= (1 << index)
            }
            if let first =  firstIndexOfCounter[counter] {
                maxLength = max(maxLength, i - first)
            } else {
                firstIndexOfCounter[counter] = i
            }
            i += 1
        }
        return maxLength
    }
 }
```