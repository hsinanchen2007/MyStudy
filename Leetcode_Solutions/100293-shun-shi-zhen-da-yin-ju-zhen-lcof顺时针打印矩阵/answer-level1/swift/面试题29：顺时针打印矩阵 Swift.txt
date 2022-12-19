```
class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        guard matrix.count > 0 else {
            return []
        }
        var left = 0
        var right = matrix.first!.count - 1
        var top = 0
        var bottom = matrix.count - 1
        var res = [Int]()
        while true {
            //left to right
            for i in left...right {
                res.append(matrix[top][i])
            }
            top += 1
            if top > bottom {
                break
            }
            //top to bottom
            for i in top...bottom {
                res.append(matrix[i][right])
            }
            right -= 1
            if left > right {
                break
            }
            //right to left
            for i in (left...right).reversed() {
                res.append(matrix[bottom][i])
            }
            bottom -= 1
            if top > bottom {
                break
            }
            //bottom to top
            for i in (top...bottom).reversed() {
                res.append(matrix[i][left])
            }
            left += 1
            if left > right {
                break
            }
        }
        return res
    }
}
```

//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass