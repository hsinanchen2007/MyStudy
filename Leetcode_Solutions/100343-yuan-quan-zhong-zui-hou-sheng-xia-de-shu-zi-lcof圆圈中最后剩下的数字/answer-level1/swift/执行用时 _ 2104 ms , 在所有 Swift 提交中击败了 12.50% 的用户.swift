### 解题思路
此处撰写解题思路
方法比较笨，一个一个删除

### 代码

```swift
class Solution {
//    例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
    func lastRemaining(_ n: Int, _ m: Int) -> Int {
        
        var arr = Array.init(repeating: 0, count: n)
        for i in 0 ..< n {
            arr[i] = i
        }
        
        var startIndex = 0
        
        while arr.count > 1 {
             startIndex = startIndex + m - 1
             startIndex = startIndex % arr.count
             arr.remove(at: startIndex)
        }
        
         return arr[0]
        
    }
}
```