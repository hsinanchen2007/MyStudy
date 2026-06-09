
## 暴力迭代

我们可以从左到右边进行迭代，对于每一根柱子，计算出从这个柱子开始向两边所能扩张的最大矩形面积，即可求出最大矩形的面积。这里稍微做一下缓存，否则会时间超限。

```swift []
class Solution {
    func largestRectangleArea(_ heights: [Int]) -> Int {
        var maxWidths: [Int] = []
        var maxArea: Int = 0
        
        for i in 0..<heights.count {
            var width = 0
            var hasCache = false
            
            for k in (0..<i).reversed() {
                guard heights[k] >= heights[i] else { break }
                width = max(maxWidths[k], width)
                if heights[k] == heights[i] { hasCache = true; break }
            }
            if !hasCache {
                for j in i..<heights.count {
                    guard heights[j] >= heights[i] else { break }
                    width += 1
                }
            }
            
            maxWidths.append(width)
            maxArea = max(maxArea, width * heights[i])
        }

        return maxArea
    }
}
```

## 分治

把柱状图中最短的柱子记作`M`，最大矩形的位置只有三种可能：
1. 以柱子`M`为高，尽可能向两边延伸而得到的矩形。
2. 在柱子`M`左侧区域。
3. 在柱子`M`右侧区域。

依据这个规则，我们可以把问题划分为子问题，分而治之。

```swift []
class Solution {
    func largestRectangleArea(_ heights: [Int]) -> Int {
        return caculateLargeArea(heights, 0, heights.count - 1)
    }
    
    private func caculateLargeArea(_ heights: [Int], _ left: Int, _ right: Int) -> Int {
        if left > right { return 0 }
        var minIndex = left
        
        for i in left...right {
            if heights[i] < heights[minIndex] {
                minIndex = i
            }
        }
        
        return [
            caculateLargeArea(heights, left, minIndex - 1),
            heights[minIndex] * (right - left + 1),
            caculateLargeArea(heights, minIndex + 1, right),
        ].max()!
    }
}
```

## 栈

无论何种算法，问题的解法都可以认为是：遍历每一颗柱子，求出以这根柱子为高，所能填充的最大矩形，然后在这些矩形中找出最大的一个。很显然，你总是需要先求出这`N`个矩形，再进行比较。

由一根柱子`i`去确定它所引导的矩形需要三个条件：矩形的高`heights[i]`、左边界`leftIndex`和右边界`rightIndex`。如果一个矩形无法再向左右扩张，它必定是遇到了比`heights[i]`要短的柱子，所以：
- `leftIndex`就是在柱子`i`的左边，**第一个短于**`heights[i]`的柱子所在的位置。
- `rightIndex`就是在柱子`i`的右边，**第一个短于**`heights[i]`的柱子所在的位置。

我们从左至右，将柱子的序号依次入栈，并且始终确保栈中柱子的高度是单调递增的。这样处理的好处是：如果我们有一个即将入栈的柱子`i`，高度小于栈顶的柱子，即`heights[i] < heights[stack.last]`，那么显然`i`就是右边界`rightIndex = i`，此时由于栈中的柱子是单调递增的，我们可以很容易的找到矩形的左边界`leftIndex = stack[stack.endIndex - 2]`（栈的倒数第二个元素）。

在具体的算法实现中，为了减少临界处理，我们在 `heights` 数组的左右两端都塞入`0`，也就是加入了两根高度为`0`的柱子。

``` swift []
class Stack {
    func largestRectangleArea(_ heights: [Int]) -> Int {
        var stack: [Int] = []
        var maxArea: Int = 0
        let heights = [0] + heights + [0]
        
        for i in 0..<heights.count {
            while let topIndex = stack.last, heights[topIndex] > heights[i] {
                stack.removeLast()
                maxArea = max(maxArea, heights[topIndex] * (i - stack.last! - 1))
            }
            stack.append(i)
        }
        
        return maxArea
    }
}
```