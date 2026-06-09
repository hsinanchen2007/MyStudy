1. 采用了动态规划: 地推公式为f(0,0) = const[0,0]+min(f(1,0),f(0,1))
    1. f(0,0) 表示救出公主需要的健康值；
    2. const[0,0]表示在该关卡不死需要的健康值
2. 添加了记忆优化
```
class Solution {
    var dicCalculateMinimumHP:[String:Int] = [:]
    func calculateMinimumHP(_ dungeon: [[Int]]) -> Int {
        dicCalculateMinimumHP.removeAll()
        let rowLen = dungeon.count
        let colLen = dungeon[0].count
        return helper174(0,0,rowLen,colLen,dungeon) + 1
    }
    /*
     帮助函数的用途：计算[rowIndex, colIndex]格子中救出公主所需要的最小生命值
     */
    func helper174(_ rowIndex:Int, _ colIndex:Int, _ rowSize:Int, _ colSize:Int, _ dungeon:[[Int]]) -> Int {
        let key = "\(rowIndex)_\(colIndex)"
        if dicCalculateMinimumHP[key] != nil {
            
            return dicCalculateMinimumHP[key]!
        }
        if rowIndex == rowSize - 1 && colIndex == colSize - 1 {//代表最后一个格子
            if dungeon[rowIndex][colIndex] >= 0 {
                dicCalculateMinimumHP[key] = 0
                return 0
            } else {
                dicCalculateMinimumHP[key] = -dungeon[rowIndex][colIndex]
                return -dungeon[rowIndex][colIndex]
            }
        } else if rowIndex < rowSize && colIndex < colSize {
            let rightMin = helper174(rowIndex, colIndex+1, rowSize, colSize, dungeon)
            let downMin = helper174(rowIndex+1, colIndex, rowSize, colSize, dungeon)
            var r = 0
            
            r = -dungeon[rowIndex][colIndex] + min(rightMin, downMin)
                
            if r < 0 {
                r = 0
            }
            
            dicCalculateMinimumHP[key] = r
            return r
        }
        dicCalculateMinimumHP[key] = Int(INT16_MAX)
        return Int(INT16_MAX)
    }

}
```
