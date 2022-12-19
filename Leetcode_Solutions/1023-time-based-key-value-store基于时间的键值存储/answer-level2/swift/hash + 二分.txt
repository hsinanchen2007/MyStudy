```
class TimeMap {

    struct VTPair {
        var values = [String]()
        var times = [Int]()
    }
    var sored: [String:VTPair] = [:]
    init() {
        
    }
    
    func set(_ key: String, _ value: String, _ timestamp: Int) {
        guard var va = sored[key] else {
            sored.updateValue(VTPair(values: [value], times: [timestamp]), forKey: key)
            return
        }
        if va.values.last! == value {
            va.times[va.times.count - 1] = timestamp
            return
        }
        va.values.append(value)
        va.times.append(timestamp)
        sored.updateValue(va, forKey: key)
    }
    
    func get(_ key: String, _ timestamp: Int) -> String {
        guard let res = sored[key] else {
            return ""
        }
        var indx = findIndex(res.times, timestamp)
        if indx > res.times.count - 1 {
            indx = res.times.count - 1
        }
        if indx == 0 && res.times[0] > timestamp {
            return ""
        }
        if res.times[indx] > timestamp {
            indx -= 1
        }
        return res.values[indx]
    }
    
    private func findIndex(_ nums: [Int], _ target: Int) -> Int {
        if nums.count == 0 {
            return 0
        }else if nums.count == 1 {
            return nums.first! > target ? 0 : 1
        }
        var left =  0
        var right = nums.count - 1
        while left <= right {
            let mid = left + (right - left) / 2
            if target > nums[mid] {
                left = mid + 1
            }else if target < nums[mid] {
                right = mid - 1
            }else {
                return mid
            }
        }
        return left
    }
}
```