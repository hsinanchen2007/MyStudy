### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func countCharacters(_ words: [String], _ chars: String) -> Int {
        var count = 0
        
        for word in words {
            
            var tempChars = chars
            var found = true
            for character in word {
                
                if let idx = tempChars.firstIndex(of:character) {
                    tempChars.remove(at: idx)
//                    print(tempChars)
                } else {
                    found = false
                    break
                }
            }
            
            if found {
                count = count + word.count
            }
            
        }
        
        return count
    }
}
```