```
    func peakIndexInMountainArray(_ A: [Int]) -> Int {
        var left = 0, right = A.count - 1
        while left <= right {
            let mid = left + (right - left) / 2
            if A[mid - 1] < A[mid] && A[mid] > A[mid + 1] {
                return mid
            }else if A[mid] < A[mid + 1] {
                left = mid + 1
            }else {
                right = mid - 1
            }
        }
        return -1
    }
```
