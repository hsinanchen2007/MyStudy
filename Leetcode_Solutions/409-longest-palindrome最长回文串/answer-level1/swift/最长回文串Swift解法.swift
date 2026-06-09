### 解题思路
找出每个字符串出现的次数，偶数肯定是回文字符串，所以我们只需要找出奇数部分，奇数里面又分为出现1次和大于1次的，对于大于1次可以被2整除的部分肯定也是回文字符串。

### 代码

```swift
class Solution {
    func longestPalindrome(_ s: String) -> Int {
        guard s.count > 0 else {
            return 0
        }
        if s.count == 1 {
            return 1
        }
        var charDic = [Character: Int]()
        for char in s {
            if let count = charDic[char] {
                charDic[char]! = count + 1
            } else {
                charDic[char] = 1
            }
        }
        var doubelCount = 0
        var singleCount = 0
        for key in charDic.keys {
            if charDic[key]! % 2 != 0 {
                singleCount = 1
            }
            doubelCount += charDic[key]! / 2 * 2 
        }
        return doubelCount + singleCount
    }
}
```