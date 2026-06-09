### 解题思路
- 最中间的一个肯定是结果
### 代码

```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        let arr = nums.sorted()
        let count = arr.count;
        return arr[count/2]
    }
}

```
- 投票法
```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var res = nums[0]
        var count = 1
        for i in 1..<nums.count {
            let temp = nums[i]
            if temp == res {
                count += 1
            } else if count == 0 {
                res = temp
            } else {
                count -= 1
            }
        }
        return res
    }
}
```
