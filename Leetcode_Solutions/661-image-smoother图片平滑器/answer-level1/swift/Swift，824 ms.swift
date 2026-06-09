```swift
class Solution {
    func imageSmoother(_ M: [[Int]]) -> [[Int]] {
        let width = M.count, height = M[0].count
        var ans = [[Int]](repeating: [Int](repeating: 0, count: height), count: width)
        for i in 0..<width {
            for j in 0..<height {
                var around = [Int]()
                let left = i > 0
                let right = i < width - 1
                let top = j > 0
                let bottom = j < height - 1
                
                around.append(M[i][j])
                if left {
                    around.append(M[i - 1][j])
                    if bottom {
                        around.append(M[i - 1][j + 1])
                    }
                }
                if top {
                    around.append(M[i][j - 1])
                    if left {
                        around.append(M[i - 1][j - 1])
                    }
                }
                if right {
                    around.append(M[i + 1][j])
                    if top {
                        around.append(M[i + 1][j - 1])
                    }
                }
                if bottom {
                    around.append(M[i][j + 1])
                    if right {
                        around.append(M[i + 1][j + 1])
                    }
                }
                ans[i][j] = around.reduce(0, +) / around.count
            }
        }
        return ans
    }
}
```