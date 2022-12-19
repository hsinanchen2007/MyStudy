### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
   func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var key1 = 0
    var key2 = 0
    for (i1, n1) in nums.enumerated() {
        for i2 in (i1+1)..<nums.count {
            let n2 = nums[i2]
            let value = n1 + n2
            if value == target {
                key1 = i1
                key2 = i2
                break
            }
        }
    }
    if (key1 == 0 && key2 == 0) == false {
        return [key1, key2]
    }
    
    return []
}


}
```