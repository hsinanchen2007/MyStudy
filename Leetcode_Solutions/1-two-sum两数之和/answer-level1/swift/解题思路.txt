### 解题思路
第一次上Leetcode刷题，现在的解题思路肯定是执行效率比较低的，慢慢来
### 代码

```swift
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
         for (i,num) in nums.enumerated() {

            for index in (i + 1..<nums.count){
                if(target - num) == nums[index]{
                    return[i,index]
                }
            }
        }
        return[]
    }
}
```