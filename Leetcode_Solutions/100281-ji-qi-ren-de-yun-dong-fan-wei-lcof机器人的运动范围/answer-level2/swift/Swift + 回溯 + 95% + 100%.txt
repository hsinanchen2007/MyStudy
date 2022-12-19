```
/这里与12题关于visited处理不太一样，计算时间会增长，无法通过，这里通过二维数据把通过的位置设置为true。
class Solution {
    let dx = [0, 1, 0, -1]
    let dy = [1, 0, -1, 0]
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        if m < 1 || n < 1 {
            return 0
        }
        var visited = [[Bool]].init(repeating: [Bool].init(repeating: false, count:n ), count: m)
        if caculate(0, 0, k) {
            return countStep(0, 0, k, m, n, &visited)
        }
        return 0
    }
    func countStep(_ m: Int, _ n: Int, _ k: Int, _ maxM: Int, _ maxN: Int, _ visited: inout [[Bool]]) -> Int {
        visited[m][n] = true
        var count = 1
        for index in 0...3 {
            let newM = m + dx[index]
            let newN = n + dy[index]
            if newM >= 0 && newM < maxM && newN >= 0 && newN < maxN {
                if !visited[newM][newN] && caculate(newM, newN, k) {
                    count  += countStep(newM, newN, k, maxM, maxN, &visited)
                }
            }
        }
        return count
    }
    
    func caculate(_ m: Int, _ n: Int, _ k: Int) -> Bool {
        var sumM = 0
        var sumN = 0
        var m = m
        var n = n
        while m > 0 {
            sumM += m % 10
            m = m / 10
        }
        while n > 0 {
            sumN += n % 10
            n = n / 10
        }
        if (sumM + sumN) > k {
            return false
        }
        return true
    }
}

```