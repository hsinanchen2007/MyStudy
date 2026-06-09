```
func peakIndexInMountainArray(_ A: [Int]) -> Int {
        let c = A.count-1
        for i in 0..<c{
            if A[i+1] < A[i]{
                return i
            }
            if A[c-i]>A[c-i-1]{
                return c-i
            }
        }
        return 1
    }
```