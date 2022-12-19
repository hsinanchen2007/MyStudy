### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func minMoves(_ nums: [Int]) -> Int {
        
        //先找出数组最小值
        var min = nums.min()!

        
        //定义返回值
        var result = 0
        
        //本质上等同于数组其它元素对最小元素的差值的和
        for num in nums {
            result += (num - min)
        }

        return  result
        
    }
}
```