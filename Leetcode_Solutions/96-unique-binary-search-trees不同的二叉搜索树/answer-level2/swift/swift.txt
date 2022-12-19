```
class Solution {
    func numTrees(_ n: Int) -> Int {
        var G = Array<Int>(repeating: 0, count: n+1)
    G[0] = 1
    G[1] = 1
    if n > 1 {
        for i in 2...n {
            for j in 1...i {
                G[i] += G[j-1] * G[i-j]
            }
        }
    }
    return G[n]
    }
}
```
