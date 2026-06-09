class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {

    var low = 0, high = matrix.count - 1
    
    while low <= high {
        
        let mid: Int = low + (high - low)/2
        
        let sortedArr = matrix[mid]
        guard !sortedArr.isEmpty else { return false }
        let first: Int = sortedArr.first!, last: Int = sortedArr.last!
        if target <= last && first <= target {
            var arrLow = 0, arrHigh = sortedArr.count - 1
            while arrLow <= arrHigh {
                let arrMid: Int = arrLow + (arrHigh - arrLow)/2
                if sortedArr[arrMid] == target {
                    return true
                } else if arrHigh == arrLow {
                    return false
                } else if sortedArr[arrMid] > target {
                    arrHigh = arrMid
                } else {
                    arrLow = arrMid + 1
                }
            }
        } else if low == high {
            return false  
        } else if first > target {
            high = mid
        } else {
            low = mid + 1
        }
    }
    return false
}
}