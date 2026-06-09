### 解题思路
计数器解法 

![image.png](https://pic.leetcode-cn.com/e7a186c37ac719bae8173bfeb749770878803e4e31adf02edb4bf746a286a6e5-image.png)


### 代码

```swift
class Solution {
        func isAnagram(_ s: String, _ t: String) -> Bool {
        
        // 计数器 0(n)
        if s.count != t.count {
            return false;
        }
        var counter = Array(repeating: 0, count: 26)
        let sarr = Array(s)
        let tarr = Array(t)
        for i in 0..<sarr.count {
            let addIdx = Int(sarr[i].asciiValue! % 26)
            let mulIdx = Int(tarr[i].asciiValue! % 26)
            counter[addIdx] = counter[addIdx] + 1
            counter[mulIdx] = counter[mulIdx] - 1
        }
        
        for val in counter {
            if val != 0 {
                return false
            }
        }
        
        return true
    }
}
```