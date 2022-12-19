就是二分查找，最左边的某一位置的值 >= len(citations)-index
```
func hIndex(citations []int) int {
	if len(citations) == 0 {
		return 0
	}

	left, right := 0, len(citations)-1
	mid := left + (right-left)>>1
	h := 0
	for left <= right {
		mid = left + (right-left)>>1
		if citations[mid] >= len(citations)-mid  {
			h = len(citations)-mid
			right = mid-1
		} else {
			left = mid+1
		}
	}
	return h
}
```
