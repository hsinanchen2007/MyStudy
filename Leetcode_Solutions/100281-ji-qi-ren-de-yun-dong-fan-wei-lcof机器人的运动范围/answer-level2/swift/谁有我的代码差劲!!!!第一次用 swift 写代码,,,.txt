### 解题思路
就 bfs 就可以, 边界判断加坐标判断

### 代码

```swift
class Solution {
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        var res = 1;
        var seen: Set<[Int]> = [[0,0]]
        var bfs = [[0, 0]]
        while !(bfs.isEmpty) {
            let ele = bfs.remove(at: 0)
            let top = ele[0] - 1
            let btm = ele[0] + 1
            let lft = ele[1] - 1
            let rgt = ele[1] + 1
            if top >= 0 && !seen.contains([top, ele[1]]) && (self.everyPlaceSum(top) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([top, ele[1]])
                seen.insert([top, ele[1]])
                res += 1
            }
            if btm < m  && !seen.contains([btm, ele[1]])  && (self.everyPlaceSum(btm) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([btm, ele[1]])
                seen.insert([btm, ele[1]])
                res += 1
            }
            if lft >= 0 && !seen.contains([ele[0], lft])  && (self.everyPlaceSum(lft) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], lft])
                seen.insert([ele[0], lft])
                res += 1
            }
            if rgt < n  && !seen.contains([ele[0], rgt])  && (self.everyPlaceSum(rgt) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], rgt])
                seen.insert([ele[0], rgt])
                res += 1
            }
        }
        return res
    }
    
    func everyPlaceSum(_ x: Int) -> Int {
        if x == 0 {
            return 0
        }
        return x % 10 + self.everyPlaceSum(x / 10)
    }
}
```