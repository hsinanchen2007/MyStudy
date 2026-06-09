```
class Solution {
    var result = [[Int]]()
    func combinationSum2(_ candidates: [Int], _ target: Int) -> [[Int]] {
        let candi = candidates.sorted()
        findCombinationSum(candidates: candi, start: 0, redius: target, arr: [])
        return result
    }
    func findCombinationSum(candidates: [Int], start: Int, redius: Int, arr: [Int]) {
        if redius == 0 {
            result.append(arr)
            return
        }
        for i in start..<candidates.count {
            if candidates[i] > redius {
                break
            }
            if i > start && candidates[i] == candidates[i - 1] {
                continue
            }
            let array = arr + [candidates[i]]
            findCombinationSum(candidates: candidates, start: i + 1, redius: redius - candidates[i], arr: array)
        }
    }
}
```