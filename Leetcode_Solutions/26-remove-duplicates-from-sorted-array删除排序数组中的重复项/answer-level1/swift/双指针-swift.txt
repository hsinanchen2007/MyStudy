### 解题思路
双指针解法，由优选java题解大神启发，重复的元素一定是相邻
1.so，定义previous为前指针，back为后指针
2.当previous 和 back 相等时，后指针back后移一位
3.当previous 和 back 不相等时，并且previous和back不是同一个位置，说明已经不是重复元素，即可以互换值，把back位置的值赋予previous+1的位置
4.互换值后，previous下标+1
5.然后继续从逻辑2开始

### 代码

```swift
class Solution {
   func removeDuplicates (_ nums: inout [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        var previous = 0
        var back = 1
        while back < nums.count {
            if nums[previous] != nums[back] {
                if back - previous > 1 {
                    nums[previous + 1] = nums[back]
                }
                previous += 1
            }
            back += 1
        }
        
        return previous + 1
    }
}
```