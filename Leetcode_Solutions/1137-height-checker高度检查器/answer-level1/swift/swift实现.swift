排序过后看看那些位置与原先位置发生了变化，记录下来即可。
```
class Solution {
    func heightChecker(_ heights: [Int]) -> Int {
        var count = 0
        for (i,v) in heights.sorted().enumerated() {
            if v != heights[i]{
                count += 1
            }
        }
        return count
    }
}
```