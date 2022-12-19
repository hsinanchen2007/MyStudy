```
class Solution {
    var result = [[Int]]()
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        let candi = candidates.sorted()
        findCombinationSum(candidates: candi, start: 0, residue: target, arr: [])
        return result
    }
    func findCombinationSum(candidates: [Int], start: Int, residue: Int, arr: [Int]) {
        if residue == 0 {
            result.append(arr)
            return
        }
        for i in start..<candidates.count{
            if candidates[i] > residue {
                break
            }
            let array = arr + [candidates[i]]
            findCombinationSum(candidates: candidates, start: i, residue: residue - candidates[i], arr: array)
        }
    }
}
```