### 解题思路
1. 从第一个到最后为一轮
2. 每一轮 删除对应的下标的值

### 代码

```swift
class Solution {
    func lastRemaining(_ n: Int, _ m: Int) -> Int {
        var arr:[Int] = Array(0..<n)
        var index = m-1
        var counter = 0
        var circleCount = arr.count
        while arr.count > 1 {
            if index >= circleCount {
                index = (index - circleCount)%arr.count
                counter = 0
                circleCount = arr.count
            }
            if index < circleCount {
                arr.remove(at: index - counter);
                counter += 1
            }
            index += m;
        }
        return arr.first ?? -1
    }
}
```