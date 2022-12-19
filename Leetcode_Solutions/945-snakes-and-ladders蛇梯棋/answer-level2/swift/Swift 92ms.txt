### 解题思路

首先，排除一开始已经在终点（即`n = 1`）的特殊情况，这种情况下结果为0。

然后，将棋盘一维化。同时，出于便于之后计算的考虑，将棋盘上大于0的值统一减1，使其能与一维棋盘的0基序号对应。

接下来，以第0格为起点开始循环。每一次循环中，记录各个起点在一步内能够到达的**新**落点，这些落点将成为下一次循环的起点。如果新落点内包含了终点，则返回当前步数；如果没有任何一个新落点，则说明终点不可达，返回-1。

### 代码

```swift
class Solution {
    func snakesAndLadders(_ board: [[Int]]) -> Int {
        let n = board.count
        if n == 1 {
            return 0
        }
        let nMinusOne = n - 1

        let length = n * n
        let lengthMinusOne = length - 1

        var values: [Int]
        do {
            values = Array(repeating: -1, count: length)

            var index = 0
            for y in 0 ..< n {
                let rowIndex = nMinusOne - y

                if y & 1 == 0 {
                    for x in 0 ..< n {
                        let value = board[rowIndex][x]
                        if value > 0 {
                            values[index] = value - 1
                        }

                        index += 1
                    }
                }
                else {
                    for x in 0 ..< n {
                        let value = board[rowIndex][nMinusOne - x]
                        if value > 0 {
                            values[index] = value - 1
                        }

                        index += 1
                    }
                }
            }
        }

        var reachables = Array(repeating: false, count: lengthMinusOne)

        var stepCount = 0
        var startIndexes: Set<Int> = [0]
        reachables[0] = true

        while true {
            stepCount += 1

            var stopIndexes: Set<Int> = []
            for startIndex in startIndexes {
                for offset in 1 ... 6 {
                    var stopIndex = startIndex + offset

                    if stopIndex >= length {
                        break
                    }

                    let value = values[stopIndex]
                    if value >= 0 {
                        stopIndex = value
                    }

                    if stopIndex == lengthMinusOne {
                        return stepCount
                    }

                    if reachables[stopIndex] {
                        continue
                    }

                    reachables[stopIndex] = true
                    stopIndexes.insert(stopIndex)
                }
            }

            if stopIndexes.isEmpty {
                return -1
            }

            startIndexes = stopIndexes
        }
    }
}
```