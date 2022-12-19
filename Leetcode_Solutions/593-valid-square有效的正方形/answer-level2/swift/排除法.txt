```
func validSquare(_ p1: [Int], _ p2: [Int], _ p3: [Int], _ p4: [Int]) -> Bool {
        func distance(_ p1: [Int], _ p2: [Int]) -> Int { // 任意两点距离平方
            let x = p1[0]-p2[0], y = p1[1] - p2[1]
            return x*x + y*y
        }
        var dic = [Int: Int]()
        let d1 = distance(p1, p2), d2 = distance(p1, p3), d3 = distance(p1, p4) 
        let d4 = distance(p2, p3), d5 = distance(p2, p4)
        let d6 = distance(p3, p4)
        var ds = Set<Int>()
        for d in [d1,d2,d3,d4,d5,d6] {
            dic[d, default: 0] += 1
            ds.insert(d)
        }
        if ds.count == 2 { // 如果是正方形, 任意两点距离只有两种长度可能（边长以及对角线）
            let ds = Array(ds)
            let e1 = min(ds[0], ds[1])  //边长
            let e2 = max(ds[0], ds[1])  //对角线
            if e1*2 == e2 // 勾股定理
              && dic[e1] == 4 && dic[e2] == 2 {
                return true
            }
        }
        return false
    }
```
