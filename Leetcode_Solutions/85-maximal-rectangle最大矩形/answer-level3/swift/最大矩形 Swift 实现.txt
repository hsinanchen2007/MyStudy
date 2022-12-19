这道题目与 [#84 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram) 非常相似。只不过 #84 是一维的，而本题需要在二维平面进行求解。

## 暴力搜索

最简单最直观的方式是对矩阵中的元素进行迭代，对于一个元素 `matrix[i][j]`，如果它是`1`，则求从 `matrix[i][j]` 向左边、上方和右边进行扩张所能得到的最大矩形。暴力搜索的时间消耗太大，会超时，不具可行性。

## 简化成柱状图进行求解。
如果你了解[#84 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram)，就会发现在本题中，连续的`1`的个数其实就是 #84 中的柱子高度。

![Group.png](https://pic.leetcode-cn.com/a200e18fa95277d9dbcfef0d976531c0b2c85c9e6053bde9cda9267e617af0af-Group.png)

```swift
class Solution {
    struct Option {
        var leftBoundary: Int
        var rightBoundary: Int
        var height: Int
        
        func area() -> Int {
            return (rightBoundary - leftBoundary + 1) * height
        }
    }
    
    func maximalRectangle(_ matrix: [[Character]]) -> Int {
        guard matrix.count > 0 else { return 0 }
        var maxArea = 0
        let m = matrix.count, n = matrix[0].count
        var options = Array<Option>(repeating: .init(leftBoundary: 0, rightBoundary: n, height: 0), count: matrix[0].count)
        
        for i in 0..<m {
            var leftBoundary = 0
            for j in 0..<n {
                if matrix[i][j] == "1" {
                    options[j].height += 1
                    options[j].leftBoundary = max(options[j].leftBoundary, leftBoundary)
                } else {
                    options[j].leftBoundary = 0
                    options[j].height = 0
                    leftBoundary = j + 1
                }
            }
            var rightBoundary = n - 1
            for j in (0..<n).reversed() {
                if matrix[i][j] == "1" {
                    options[j].rightBoundary = min(options[j].rightBoundary, rightBoundary)
                } else {
                    rightBoundary = j - 1
                    options[j].rightBoundary = n - 1
                }
                maxArea = max(maxArea, options[j].area())
            }
        }
        
        return maxArea
    }
}
```

## 动态规划

![image.png](https://pic.leetcode-cn.com/4b096804a83388e8e311dc469e76e3c5eaea91dfe02d0763b95c9a910a6e7191-image.png)

从动态规划的角度，可以把这个问题划分成4个子结构，也就是按行自上而下的遍历整个矩阵，对应着上面图片里的四个子图。
对于每一个子结构，我们遍历它最后一行上的元素：对于元素`matrix[i][j]`，去寻找从这个元素出发，向左、上、右尽可能扩张，所能得到的最大矩形，也就是三个要素：矩形的高、左边界和右边界。

矩形的高`height`是非常容易确定的，实际上就是从当前元素出发向上搜索，连续的`1`的个数。然后我们可以继续求解矩形的左右边界，使用动态规划的核心点在于，左、右边界是可以根据上一行的结果进行计算得到的，即元素`matrix[i][j]`处的矩形的`leftBoundaries[i][j]`可以由`leftBoundaries[i - 1][j]`求得，`rightBoundaries[i][j]`可以由`rightBoundaries[i-1][j]`求得。

```swift
// 对某一行就行遍历，求每一个元素处的矩形高度
for j in 0..<matrix[i].count {
    if matrix[i][j] == "1" {
        heights[i][j] = heights[i - 1][j] + 1
    } else {
        heights[i][j] = 0
    }
}

// 对某一行就行遍历，求每一个元素处的矩形的左边界
var leftBoundary = 0
for j in 0..<matrix[i].count {
    if matrix[i][j] == "1" {
        leftBoundaries[i][j] = max(leftBoundaries[i][j], leftBoundary)
    } else {
        // 高度为 0 的矩形，它的左边界为0。因为它没有障碍，可以“无限延伸”。
        leftBoundaries[i][j] = 0
        // 当前元素为“0”，可能会阻碍下一个（右边）元素处的矩形的扩张。对于下一个元素，若为“1”，它的矩形左边界肯定不会小于`j+1`。
        leftBoundary = j + 1
    }
}

// 求解右边界的原理与左边界相同。
```

完整代码：

```swift []
class DP {
    struct Option {
        var leftBoundary: Int
        var rightBoundary: Int
        var height: Int
        
        func area() -> Int { return (rightBoundary - leftBoundary + 1) * height }
    }
    
    func maximalRectangle(_ matrix: [[Character]]) -> Int {
        guard matrix.count > 0 else { return 0 }
        var maxArea = 0
        let m = matrix.count, n = matrix[0].count
        var options = Array<Option>(repeating: .init(leftBoundary: 0, rightBoundary: n, height: 0), count: matrix[0].count)
        
        for i in 0..<m {
            var leftBoundary = 0
            for j in 0..<n {
                if matrix[i][j] == "1" {
                    options[j].height += 1
                    options[j].leftBoundary = max(options[j].leftBoundary, leftBoundary)
                } else {
                    options[j].leftBoundary = 0
                    options[j].height = 0
                    leftBoundary = j + 1
                }
            }
            var rightBoundary = n - 1
            for j in (0..<n).reversed() {
                if matrix[i][j] == "1" {
                    options[j].rightBoundary = min(options[j].rightBoundary, rightBoundary)
                } else {
                    rightBoundary = j - 1
                    options[j].rightBoundary = n - 1
                }
                maxArea = max(maxArea, options[j].area())
            }
        }
        
        return maxArea
    }
}
```