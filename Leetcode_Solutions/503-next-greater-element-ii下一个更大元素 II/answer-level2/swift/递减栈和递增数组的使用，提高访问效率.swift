### 解题思路
这道题目类似于下一个更大元素I，解题思路一样，stack存储还未找到下一个更大元素的索引，每次遍历的时候判断是否满足要求，满足则循环推出栈，不满足则入栈，栈是一个单调递减的。

唯一不同就是这道题目的数组是个循环的，官方做法则是直接访问两次数组，我的做法稍有不同，保存一个递增数组，这样会少很多的元素访问。

### 代码

```swift
class Solution {
    func nextGreaterElements(_ nums: [Int]) -> [Int] {
        var stack = [Int]()
        var result = [Int]()
        var increase = [Int]()
        for i in 0..<nums.count {
            while let last = stack.last, nums[last] < nums[i] {
                result[last] = nums[i]
                stack.popLast()
            }
            result.append(-1)
            stack.append(i)
            let more = increase.last ?? Int.min
            if more < nums[i] {
                increase.append(nums[i])
            }
            
        }
        for i in increase  {
            while let last = stack.last, nums[last] < i {
                result[last] = i
                stack.popLast()
            }
        }
        return result

    }
}
```