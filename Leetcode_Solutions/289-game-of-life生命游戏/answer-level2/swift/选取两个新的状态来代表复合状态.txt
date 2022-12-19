### 解题思路
1、复制一个然后模拟，没什么难度，但是空间复杂度太大
2、使用复合状态来原地计算，比如 -1 代表 过去是1，现在是0； 2 代表过去是0， 现在是1。当然也可以使用任意的数字来代替，主要是能从改变后的数字获取到之前的状态是1还是0.

### 代码

```swift
class Solution {
func gameOfLife(_ board: inout [[Int]]) {

    let r = board.count
    let c = board[0].count

    // -1 代表过去是活的，现在死了
    // 2 代表过去是死的，现在是活的

    let dxy = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]


    for i in 0..<r {
        for j in 0..<c {

            var tl = 0
            for dp in dxy {
                let dx = dp.0 + i
                let dy = dp.1 + j

                if dx >= 0 &&  dx <  r && dy >= 0 && dy < c {
                    let v = board[dx][dy]
                    switch v {
                    case -1, 1:
                        tl += 1
                    case 0, 2:
                        tl += 0
                    default: break
                    }
                }
            }

            let cv = board[i][j]

            var newV = 0
            // 应用规则
            if tl < 2 {
                newV = cv == 0 ?  0 :  -1
            } else if tl == 2 || tl == 3 {
                newV = cv == 1 ? 1 : (tl == 3 ? 2 : cv)
            } else if tl > 3 {
                newV = cv == 1 ? -1 : 0
            }

            board[i][j] = newV
        }
    }

    for i in 0..<r {
        for j in 0..<c {
            switch board[i][j] {
            case -1:
                board[i][j] = 0
            case 2:
                board[i][j] = 1
            default: break
            }
        }
    }
}

}
```