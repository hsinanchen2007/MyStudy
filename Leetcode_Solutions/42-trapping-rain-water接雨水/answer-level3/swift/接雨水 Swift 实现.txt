

## 栈
使用栈的主要思想是：对于一个可行的储水结构（一个凹陷），我们无法一次求的水量，但是可以把它拆成若干个子结构，从内层向外层逐步求的水量。也就是把整个问题拆分成若干个子问题，不要贪婪，每次都只是解决一个子问题。
- 至少需要三个柱子来判断是否是一个可行的储水结构，所以子问题就是考察3根柱子：栈顶的2个柱子和即将入栈的1根柱子。
- 在求得子结构（3根柱子）的蓄水量后会有柱子出栈，中间的柱子将会出栈。
- 不要重复计算已解的子结构的水量。

```swift
class Solution {
    func trap(_ height: [Int]) -> Int {
        var stack: [Int] = []
        var total: Int = 0
        
        for i in 0..<height.count {
            while let topIndex = stack.last, height[i] > height[topIndex] {
                stack.removeLast()
                
                guard let lastIndex = stack.last else { break }
                
                let distance = i - lastIndex - 1
                let gap = min(height[i], height[lastIndex]) - height[topIndex]
                
                total += gap * distance
            }
            
            stack.append(i)
        }
        
        return total
    }
}
```

## 双指针法

就像木桶原理那样，木桶的水面高度，由最短的木板决定。本题中，某个柱子上方的蓄水量，是由这个柱子左侧最高的柱子和右侧最高的柱子中较矮的那一个决定的，所以我们关心的是“较矮”的柱子。

用两个指针`left`和`right`分别从左和右向中间逼近，在这一过程中更新最大柱高`maxHeight.left`和`maxHeight.right`。

```swift []
class Solution {
    func trap(_ height: [Int]) -> Int {
        var left: Int = 0, right: Int = (height.count - 1)
        var total: Int = 0
        var maxHeight: (left: Int, right: Int) = (0, 0)
        
        while left < right {
            if height[left] < height[right] {
                if height[left] > maxHeight.left {
                    maxHeight.left = height[left]
                } else {
                    total += (maxHeight.left - height[left])
                }
                left += 1
            } else {
                if height[right] > maxHeight.right {
                    maxHeight.right = height[right]
                } else {
                    total += (maxHeight.right - height[right])
                }
                right -= 1
            }
        }
        
        return total
    }
}
```