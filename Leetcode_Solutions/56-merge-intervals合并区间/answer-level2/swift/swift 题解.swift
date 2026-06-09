
    主要思路是先排序，再求区间

    class Solution {
        func merge(_ intervals: [[Int]]) -> [[Int]] {
            let newIntervals = intervals.sorted { (a: [Int], b: [Int]) -> Bool in
                return a[0] > b[0] ? false:true
            }
            var res = [[Int]]()
            if (newIntervals.count > 0){
                var current: [Int] = newIntervals[0]
                for index in 1..<newIntervals.count {
                    let element: [Int] = newIntervals[index]
                    if current[1] >= element[0] {
                        if (current[1] < element[1]){
                            current[1] = element[1]
                        }
                    }else{
                        res.append(current)
                        current = element
                    }
                }
                res.append(current)
            }
            
            return res
        }
    }