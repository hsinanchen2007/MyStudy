### 解题思路
第一次先循环把字符的出现次数统计出来，
然后循环遍历字符串数组，判断每个字符串是否满足

### 代码

```swift
class Solution {
    func countCharacters(_ words: [String], _ chars: String) -> Int {
        var dic:[Character: Int] = [:]
        for char in chars {
            dic[char] = (dic[char] ?? 0) + 1
        }
        var count = 0
        for str in words {
            var matched = true
            var temp = dic 
            for char in str {
                if let n = temp[char] {
                    if n > 0 {
                       temp[char]! -= 1;
                     } else {
                         matched = false
                        break
                     }
                } else {
                     matched = false
                    break
                }
             }
            if(matched) {
                count += str.count
            }
        }
        return count
    }
}
```