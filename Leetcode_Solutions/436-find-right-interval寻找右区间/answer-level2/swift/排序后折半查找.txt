```
class Solution {
    func findRightInterval(_ intervals: [[Int]]) -> [Int] {
        var dic:[String:Int] = [:]
        var index = 0
        var res:[Int] = Array(repeating: 0, count: intervals.count)
        for item in intervals {
            dic["\(item[0])_\(item[1])"] = index
            index += 1
        }
        var mutbleIntervals = Array(intervals)
        mutbleIntervals.sort { (a, b) -> Bool in
            return a[0] < b[0]
        }
        for i in 0...mutbleIntervals.count-1 {
            let r = helper436Binary_search(mutbleIntervals, mutbleIntervals[i][1], 0, mutbleIntervals.count-1)
            if let r = r {
                res[dic["\(mutbleIntervals[i][0])_\(mutbleIntervals[i][1])"]!] = dic["\(r[0])_\(r[1])"]!
            } else {
                res[dic["\(mutbleIntervals[i][0])_\(mutbleIntervals[i][1])"]!] = -1
            }
        }
        return res
    }
    public func helper436Binary_search(_ intervals: [[Int]], _ target:Int,_ begin:Int, _ end:Int) -> [Int]?{
        if begin >= end {
            if intervals[begin][0] >= target {
                return intervals[begin]
            } else {
                return nil
            }
        }
        let mid = (begin + end)/2
        if intervals[mid][0] >= target {
            return helper436Binary_search(intervals, target, begin, mid)
        } else {
            return helper436Binary_search(intervals, target, mid+1, end)
        }
    }

}
```
