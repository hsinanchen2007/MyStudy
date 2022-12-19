### Map
遍历一遍nums，将其添加到map中，同时判断元素的个数是否大于数组的一半，是则返回
```
func majorityElement(nums []int) int {
	m := len(nums) / 2
	res := make(map[int]int)

	for _, v := range nums {
		res[v]++
		if res[v] > m {
			return v
		}
	}

	return -1
}

```
### 分治，官方题解的golang实现。便于阅读
```
func majorityElement(nums []int) int {
	return majority(nums, 0, len(nums)-1)
}

func majority(nums []int, lo, hi int) int {
	// base case; the only element in an array of size 1 is the majority element.
	if lo == hi {
		return nums[lo]
	}

	// recurse on left and right halves of this slice.
	mid := (hi-lo)/2 + lo
	left := majority(nums, lo, mid)
	right := majority(nums, mid+1, hi)

	// if the two halves agree on the majority element, return it.
	if left == right {
		return left
	}

	// otherwise, count each element and return the "winner".
	leftCount := countInRange(nums, left, lo, hi)
	rightCount := countInRange(nums, right, lo, hi)
	if leftCount > rightCount {
		return left
	} else {
		return right
	}
}

func countInRange(nums []int, num, lo, hi int) int {
	count := 0
	for i := lo; i <= hi; i++ {
		if nums[i] == num {
			count++
		}
	}
	return count
}
```