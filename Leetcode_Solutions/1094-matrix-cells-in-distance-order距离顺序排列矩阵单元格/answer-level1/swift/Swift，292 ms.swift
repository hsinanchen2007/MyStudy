```swift
class Solution {
    func allCellsDistOrder(_ R: Int, _ C: Int, _ r0: Int, _ c0: Int) -> [[Int]] {
        var ans = [[Int]]()
        for i in 0...(R + C) {
            var set = Set<[Int]>()
            for offsetR in 0...i {
                let offsetC = i - offsetR
                
                var newR = r0 + offsetR
                var newC = c0 + offsetC
                if newR < R && newC < C {
                    set.insert([newR, newC])
                }
                newR = r0 + offsetR
                newC = c0 - offsetC
                if newR < R && newC >= 0 {
                    set.insert([newR, newC])
                }
                newR = r0 - offsetR
                newC = c0 + offsetC
                if newR >= 0 && newC < C {
                    set.insert([newR, newC])
                }
                newR = r0 - offsetR
                newC = c0 - offsetC
                if newR >= 0 && newC >= 0 {
                    set.insert([newR, newC])
                }
            }
            if set.count <= 0 { break }
            ans.append(contentsOf: Array(set))
        }
        return ans
    }
}
```