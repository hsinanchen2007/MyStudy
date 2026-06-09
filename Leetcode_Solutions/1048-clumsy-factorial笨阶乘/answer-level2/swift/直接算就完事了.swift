直接算 没有那么多花里胡哨的
```
class Solution {
    func clumsy(_ N: Int) -> Int {
        var rate = N
        var res = 0
        var pos = 0
        for i in stride(from: N - 1, through: 1, by: -1) {
            switch pos {
                case 0:
                    rate = rate * i
                    break
                case 1:
                    rate = rate / i
                    break
                case 2:
                    res = res + rate + i
                    rate = 0
                    break
                case 3:
                    rate = -i
                    break
                default:
                    break
            }
            pos = (pos + 1) % 4
        }
        res = res + rate
        return res
    }
}
```