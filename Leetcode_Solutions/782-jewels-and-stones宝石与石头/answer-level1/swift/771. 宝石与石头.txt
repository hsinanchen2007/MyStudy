### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func numJewelsInStones(_ J: String, _ S: String) -> Int {
        
        let nums = S.filter {
            J.contains($0)
        }
        return nums.count
    }
}
```

利用Swift的高级函数（filter）