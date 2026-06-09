### 解题思路

向量的特性

### 代码

```swift
class Solution {
    func minTimeToVisitAllPoints(_ points: [[Int]]) -> Int {
        
        //定义返回值
        var ans = 0
        
        //遍历嵌套数组
        for index in 0..<points.count - 1 {
            
            //定义两个变量分别表示两个相邻点的，沿着x轴方向和Y轴方向之间的距离
            var dX = 0
            var dY = 0
            
            //这里也可以写成x1 = points[index][0]或者y1 = points[index][1]
            if let x1 = points[index].first,let x2 = points[index + 1].first {
                dX = abs(x1 - x2)
            }
            if let y1 = points[index].last,let y2 = points[index + 1].last {
                dY = abs(y1 - y2)
            }
            
            //两个相邻点之间的最短距离即是该两点沿着X轴方向和Y轴方向距离的最大的那个值
            ans += max(dX, dY)
        }

        
        return ans
    }
}
```