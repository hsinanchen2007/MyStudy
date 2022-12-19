```swift
class Solution {
    let xOffset = [1, 0 , -1 , 0]
    let yOffset = [0, 1, 0, -1]

    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        var array = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
        array[0][0] = true
        
        var cur = [(Int, Int)]()
        cur = [(0, 0)]
        var ans = 1
        while !cur.isEmpty {
            let last = cur.removeLast()
            
            for i in 0...3 {
                let x = last.0 + xOffset[i]
                let y = last.1 + yOffset[i]
                if x >= m || x < 0 || y >= n || y < 0 {
                    continue
                }
                if array[x][y] {
                    continue
                }
                if getSum(x) + getSum(y) > k {
                    continue
                }
                array[x][y] = true
                cur.append((x, y))
                ans += 1
            }
        }
        return ans
    }

    func getSum(_ num: Int) -> Int {
        var ans = 0
        var num = num
        while num != 0 {
            ans += num % 10
            num = num / 10
        }
        return ans
    }
}
```
