### 解题思路
双百简单思路， 首先创建一个都为零的二阶数组arr，用来存放周围“1”的数量，然后开始遍历board，只需要在遇到“1”时，将周围的8个格子加1即可。
对于board[i][j]的值满足 arr[i][j]为3 或者 arr[i][j]为2且board[i][j]为1 时 设置为1即可，其他情况皆为0.

### 代码

```swift
class Solution {
    func gameOfLife(_ board: inout [[Int]]) {
        var arr = Array(repeating:
            Array(repeating: 0,
                count: board.first?.count ?? 0),
                        count: board.count)
        
        let count = board.count
        var i_count: Int
        for i in 0..<count {
            i_count = board[i].count
            for j in 0..<i_count {
                // 只需要对是1的进行操作
                if board[i][j] == 1 {
                    for m in [-1, 0, 1] {
                        for n in [-1, 0, 1] {
                            if m == 0 && n == 0 {
                                continue
                            }
                            
                            if i + m < 0 || j + n < 0 {
                                continue
                            }
                            if i + m >= count || j + n >= i_count {
                                continue
                            }

                            // 如果是周围且不越界则加一
                            arr[i + m][j + n] += 1
                        }
                    }
                }
            }
        }
        
    for i in 0..<count {
        i_count = board[i].count
        for j in 0..<i_count {
            board[i][j] = (arr[i][j] == 3 || (arr[i][j] == 2 && board[i][j] == 1)) ? 1 : 0
        }
    }
        
    }
}
```