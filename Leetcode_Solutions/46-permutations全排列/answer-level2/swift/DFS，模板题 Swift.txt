DFS, 方向是各个方向都能搜，用一个数组记录有没有被访问过，由于要输出所有结果，所以记得要重置
```
class Solution {
    func permuteHelper(_ nums: [Int], _ idx: Int, _ cur: [Int], _ vis: inout [Bool], _ res: inout [[Int]]) {
        let len = nums.count
        if cur.count == len {
            res.append(cur)
            return
        }
        for i in 0 ..< len {
            if vis[i] == false {
                vis[i] = true
                permuteHelper(nums, i, cur + [nums[i]], &vis, &res)
                vis[i] = false
            }
        }
    }

    func permute(_ nums: [Int]) -> [[Int]] {
        let len = nums.count
        if len == 0 {
            return [[Int]]()
        }
        var res = [[Int]]()
        var vis = Array(repeating: false, count: len)
        permuteHelper(nums, 0, [Int](), &vis, &res)
        return res
    }
}
```