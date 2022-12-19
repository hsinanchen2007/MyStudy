```
class Solution {
    func fib(_ n: Int) -> Int {
        var visited = [Int].init(repeating: 0, count: n + 1)
        if n == 0 || n == 1 {
            return n
        }
        visited[0] = 0
        visited[1] = 1
        for index in 2...n {
            visited[index] = (visited[index - 1] + visited[index - 2]) % 1000000007
        }
        return visited[n]
    }
}
```