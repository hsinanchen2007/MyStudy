```
class Solution {
    func smallestDistancePair(_ nums: [Int], _ k: Int) -> Int {
        var mutnum = nums
        mutnum.sort { (n1, n2) -> Bool in
            return n1 < n2
        }
        var min = 0
        var max = mutnum[nums.count - 1] - mutnum[0]
        while min < max {
            let mid = min + (max - min) / 2
            var left = 0
            var count = 0
            for right in 0...mutnum.count-1 {
                while mutnum[right] - mutnum[left] > mid {
                    left += 1
                }
                count += right - left
            }
            
            if count >= k {
                 max = mid
            }else{
                min = mid + 1
            }
        }
        return min
    }
}
```