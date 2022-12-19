### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func minDistance(_ word1: String, _ word2: String) -> Int {
        
      if word1 == word2 {
            return 0
        }
        if word2 == "" {
            return word1.count
        }
        
        if word1 == "" {
            return word2.count
        }
        
        let word1Arr = Array.init(word1)
        let word2Arr = Array.init(word2)
        var table = Array.init(repeating: Array.init(repeating: 0, count: word2.count + 1), count: word1.count + 1)
  
        for i in 0 ... word1Arr.count {
            table[i][0] = i
        }
        
        for j in 0 ... word2Arr.count {
            table[0][j] = j
        }
        
        for i in 0 ..< word1Arr.count {
            
            let word1Val:Character = word1Arr[i]
            
            for j in 0 ..< word2Arr.count {
                
                let word2Val:Character = word2Arr[j]
                
                let tableX = i + 1
                let tableY = j + 1
                
                let leftDown = table[tableX-1][tableY] + 1
                let top = table[tableX][tableY-1] + 1
                var leftTop = table[tableX-1][tableY-1] + 1
                if word1Val == word2Val {
                    leftTop = table[tableX-1][tableY-1]
                }
                
                table[tableX][tableY] = min(top, leftDown, leftTop)
            }
        }
        
        return table[word1.count][word2.count]
    }
}
```