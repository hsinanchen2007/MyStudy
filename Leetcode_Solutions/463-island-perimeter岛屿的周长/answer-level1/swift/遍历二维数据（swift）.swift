### 解题思路
直接对二维数据进行遍历循环。当碰到1时边数+4，再检测1的左侧数字是否为1，若为1则直接-2（重合两条边缘故），接着检测1的上侧数字是否为1，若为1再-2

### 代码

```swift
class Solution {
    func islandPerimeter(_ grid: [[Int]]) -> Int {
        if grid.count == 0{
            return 0
        }
        var result = 0
        for (idx, item) in grid.enumerated() {
            for (subIdx, subItem) in item.enumerated() {
                if subItem == 1 {
                    result += 4
                    // 检测左侧数字
                    if subIdx != 0 && item[subIdx - 1] == 1 {
                        result -= 2
                    }
                    // 检测上侧数字
                    if idx != 0 && grid[idx - 1][subIdx] == 1{
                        result -= 2
                    }
                } 

            }
        }
        return result
    }
}
```