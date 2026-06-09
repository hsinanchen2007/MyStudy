1. 第一次做，不会，查，知道了[84题](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)可以用来解这题
2. 去看84题，没好的想法，看评论说单调栈，知识盲区，找资料
3. 知道了[739.每日温度](https://leetcode-cn.com/problems/daily-temperatures/)，暴力超时的情况下去看了单调栈，差不多理解了。
4. 回到84题
5. 回到85题
```
class Solution {
    func maximalRectangle(_ matrix: [[Character]]) -> Int {
        let m = matrix.count
        if m == 0 {
            return 0
        }
        let n = matrix[m-1].count
        if n == 0 {
            return 0
        }
        let d: [Character:Int] = ["0":0, "1":1]
        var nmtx = Array(repeating: Array(repeating: 0, count: n), count: m)
        for (i, g) in matrix.enumerated() {
            for (j, c) in g.enumerated() {
                if i == 0 {
                    nmtx[i][j] = d[c]!
                }else{
                    if d[c]! == 0 {
                        nmtx[i][j] = 0
                    }else{
                        nmtx[i][j] = nmtx[i-1][j] + 1
                    }
                    
                }
            }
        }
        var res = 0
        var stack = [Int]()
        for g in nmtx {
            for i in 0...g.count {
                let cur = i == g.count ? -1 : g[i]
                while stack.count > 0 && cur < g[stack.first!] {
                    let top = stack.first!
                    stack.removeFirst()
                    res = max(res, g[top]*(stack.count==0 ? i : i - stack.first! - 1))
                }
                stack.insert(i, at: 0)
            }
            
            stack.removeAll()
            
        }
        return res
    }
}
```