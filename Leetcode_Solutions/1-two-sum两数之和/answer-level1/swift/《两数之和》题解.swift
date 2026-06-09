### 解题思路
此题的解决思路为：
求两数之和为一个目标值，由此可以判断，需要进行双层循环求得此解，且第一层循环只需要执行（数组长度-1）次，第二层循环索引的起始为(当前第一层循环执行的次数+1)。

### 代码

```swift
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var i_ = 0
        var j_ = 0
        for i in 0..<nums.count - 1 {
            for j in i+1..<nums.count {
                if nums[i] + nums[j] == target {
                    i_ = i;
                    j_ = j
                    break;
                }
            }
        }
        return [i_, j_]
    }
}
```