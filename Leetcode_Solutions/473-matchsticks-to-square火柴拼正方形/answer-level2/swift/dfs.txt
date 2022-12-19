```
class Solution {
    func makesquare(_ nums: [Int]) -> Bool {
        if nums.count < 4 {
            return false
        }
        var sum = 0
        for n in nums {
            sum += n
        }
        
        if sum % 4 != 0 {
            return false
        }
        let single = sum / 4
        if nums.last! > single {
            return false
        }
        var borders = [0,0,0,0]
        let tmp = nums.sorted { (n1, n2) -> Bool in
            return n2 < n1
        }
        return dfs(tmp, &borders, 0, single)
    }
    
    func dfs(_ nums: [Int], _ edges: inout [Int], _ j: Int, _ average: Int) -> Bool {
        if j >= nums.count {
            return edges[0] == average && edges[1] == average && edges[2] == average && edges[3] == average
        }
        for i in 0...3 {
            if edges[i] + nums[j] > average {
                continue
            }
            edges[i] += nums[j]
            if dfs(nums, &edges, j+1, average) {
                return true
            }
            edges[i] -= nums[j]
        }
        return false
    }
}
```