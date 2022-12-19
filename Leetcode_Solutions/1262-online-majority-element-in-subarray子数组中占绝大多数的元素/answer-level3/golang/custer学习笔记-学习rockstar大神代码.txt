```go
type MajorityChecker struct {
    arr []int
}


func Constructor(arr []int) MajorityChecker {
    return MajorityChecker{
		arr: arr,
	}
}


func (this *MajorityChecker) Query(left int, right int, threshold int) int {
	cnt := 0
	curr := 0
	for i := left; i <= right; i++ {
		if cnt == 0 {
			curr = this.arr[i]
		}
		if curr == this.arr[i] {
			cnt++
		} else {
			cnt--
		}
	}
	cnt = 0
	for i := left; i <= right; i++ {
		if curr == this.arr[i] {
			cnt++
		}
	}
	if cnt >= threshold {
		return curr
	}
	return -1
}
```
