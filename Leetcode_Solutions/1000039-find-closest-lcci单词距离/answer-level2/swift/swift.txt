### 解题思路
憨批解法....
使用数组中两个给定word首次出现的索引初始化position，再遍历数组，遇到新的word就更新position求差，取最小值差值返回
感觉一点都不优雅（爆哭

### 代码

```swift
class Solution {
    func findClosest(_ words: [String], _ word1: String, _ word2: String) -> Int {

        var position1 = -1
        var position2 = -1
        var index = 0
        var closest = 100000 //初始化最近的距离为 ∞
        var diff = 0
        var indexForWhile = 0
        while(indexForWhile<=words.count-1){
            if words[indexForWhile] == word1 {
                position1 = indexForWhile
            }
            if words[indexForWhile] == word2 {
                position2 = indexForWhile
            }
            if position1 != -1 && position2 != -1 {
                break
            }
            indexForWhile += 1
        }
        for string in words {
            diff = 10000
            if string == word1 {
                position1 = index
            }
            if string == word2 {
                position2 = index
            }
            if position2 > position1 {
                diff = position2-position1
                closest = min(closest, diff)
            } else {
                diff = position1-position2
                closest = min(closest, diff)
            }
           
            index += 1
        }
        return closest
    }
}
```