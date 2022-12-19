1. 先对houses和heaters排序。
2. 遍历houses，对于每一个house，判断其到两侧的heater之间的距离（这里有二分），取较小的那个。
3. 2的结果里最大的那个就是最终结果。
```
class Solution {
    func findRadius(_ houses: [Int], _ heaters: [Int]) -> Int {
        let sortHouses = houses.sorted { (h1, h2) -> Bool in
            return h1 < h2
        }
        let sortHeaters = heaters.sorted { (h1, h2) -> Bool in
            return h1 < h2
        }
        var res = 0
        for h in sortHouses {
            let idx = bs(sortHeaters, h)
            
            var d1 = 0
            if idx >= sortHeaters.count {
                d1 = abs(h - sortHeaters[idx-1])
            }else{
                d1 = abs(h - sortHeaters[idx])
                if sortHeaters[idx] != h && idx > 0 {
                    d1 = min(d1, abs(h - sortHeaters[idx-1])) 
                }
            }
            res = max(res, d1)
        }
        return res
    }
    
    private func bs(_ nums: [Int], _ target: Int) -> Int {
        var max = nums.count - 1
        var min = 0
        while min <= max {
            let mid = min + (max - min) / 2
            if nums[mid] > target {
                max = mid - 1
            }else if nums[mid] < target {
                min = mid + 1
            }else{
                return mid
            }
        }
        return min
    }
}
```