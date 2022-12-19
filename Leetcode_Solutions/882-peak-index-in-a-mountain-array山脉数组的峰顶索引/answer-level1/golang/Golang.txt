```
func peakIndexInMountainArray(A []int) int {
    for {
		if len(A) == 1 {
			return 0
		}
		if len(A) == 2 {
			if A[0] > A[1] {
				return 0
			}
			return 1
		}
		mid := len(A) / 2

		if A[mid] >= A[mid-1] && A[mid] > A[mid+1] {
			return mid
		}

		if A[mid] < A[mid-1] {
			return peakIndexInMountainArray(A[:mid])
		}

		if A[mid] < A[mid+1] {
			return mid + peakIndexInMountainArray(A[mid:])
		}
	}
}
```
