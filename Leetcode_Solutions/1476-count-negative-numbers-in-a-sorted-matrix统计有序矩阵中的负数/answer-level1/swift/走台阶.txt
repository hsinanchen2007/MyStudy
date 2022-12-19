### 解题思路
也可以用二分法
### 代码

```swift
class Solution {
    func countNegatives(_ grid: [[Int]]) -> Int {
        
        //初始化下一次遍历时的起始点
        var startIndex = 0
        //初始化返回值
        var result = 0
        
        //从二维数组左下角朝着右上角遍历。因为二维数组无论行列都是递减排列，所以上面一行遍历起始的索引等于下面一行最后一个非负数的索引+1
        for arr in grid.reversed() {
            
            for index in startIndex..<arr.count {
                
                if arr[index] < 0 {
                    result += 1
                }
                
                if arr[index] >= 0 {
                    startIndex = index + 1
                }
            }
        }
        
        return result
    }
    
}
```