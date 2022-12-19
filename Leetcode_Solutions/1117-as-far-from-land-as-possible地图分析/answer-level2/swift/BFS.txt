### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
       func maxDistance(_ grid: [[Int]]) -> Int {
        var grid = grid
        let count = grid.flatMap{$0}.filter{$0 == 0}.count
        if count == 0 {
            return -1
        }
        var queue:[(Int,Int)] = [(Int,Int)]()
        let m = grid.count
        let n = grid[0].count

        for i in 0 ..< m {
            for j in 0 ..< n {
                if grid[i][j] == 1 {
                    queue.append((i,j))
                }
            }
        }
        var point:(Int,Int) = (0,0)
        
        let dx = [0,0,1,-1]
        let dy = [1,-1,0,0]

        while !queue.isEmpty {
            point = queue.removeFirst()
            for i in  0 ..< 4 {
                let x = point.0 + dx[i]
                let y = point.1 + dy[i]
                if x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0 {
                    continue
                }
                grid[x][y] = grid[point.0][point.1] + 1
                queue.append((x , y))
            }
        }

        return grid[point.0][point.1] - 1;
    }
}
```