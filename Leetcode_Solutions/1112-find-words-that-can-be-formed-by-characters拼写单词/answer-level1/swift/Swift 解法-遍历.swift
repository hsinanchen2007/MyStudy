### 解题思路

分别统计每个单词是否能够用字母表拼出

### 代码

```swift
class Solution {
        func countCharacters(_ words: [String], _ chars: String) -> Int {
        var ch = chars.utf8CString
        ch.removeLast()
        var arr = Array(repeating: 0, count: 26)
        for i in ch {
            arr[Int(i)-97] += 1;
        }
        
        var res = 0
        for i in words {
            res += i.count
            var copy = arr
            var w = i.utf8CString
            w.removeLast()

            for j in w {
                let index = (Int(j) - 97)
                let curr = copy[index]
                if (curr > 0) {
                    copy[index] = curr - 1
                } else {
                    res -= i.count
                    break
                }
            }
        }
        
        return res
    }
}
```