### 暴力解法
```
class Solution {

    func largestRectangleArea(_ heights: [Int]) -> Int {
        let nums = heights.count 
        if nums == 0 {
            return 0
        }
        var maxArea = 0
        for i in 0..<nums {
            var minHeight = heights[i]
            for j in i..<nums {
                minHeight = min(minHeight, heights[j])
                maxArea = max(maxArea, (j - i + 1) * minHeight)
            }
        }
        return maxArea
    }
}
```

### 单调栈

```swift
class Solution {
    func largestRectangleArea(_ heights: [Int]) -> Int {
        if  heights.count  == 0 {
            return 0
        }
        var stack: [Int] = []
        // 解决边界问题
        let heights = [0] + heights + [0]
        var maxArea = 0
        for i in 0..<heights.count {
           while !stack.isEmpty && heights[stack.last!] > heights[i] {
               let lastIndex = stack.last!
               stack.removeLast()
               maxArea = max(maxArea, heights[lastIndex] * (i - stack.last! - 1))
           }
           stack.append(i)
        }
        return maxArea
    }
}
```