### 解题思路 1
循环迭代

### 代码 1

```swift
class Solution {
    func shiftGrid(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        
        //定义返回数组的初始化状态为输入数组
        var ans = grid
        
        //定义循环迁徙次数
        var count = k
        while count > 0 {
            
            //初始化第一个迁徙的元素=初始数组的最末尾一个元素
            var lastNumber = ans.last?.last ?? 0
            
            //循环数组，先插再删
            for (index,arr) in ans.enumerated() {
                
                ans[index].insert(lastNumber, at: arr.startIndex)
                lastNumber = ans[index].removeLast()
            }

            count -= 1
        }

        return ans
        
    }
}
```