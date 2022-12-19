依次遍历数组先固定第一个和的子元素，然后在后面的元素中二分查找另一个子元素
```
func twoSum(numbers []int, target int) []int {
	result := make([]int, 2)
	for i := 0; i < len(numbers)-1; i++ {
		r := search(numbers, i+1, len(numbers)-1, target-numbers[i])
		if r != -1 {
			result[0] = i+1
			result[1] = r+1
			break
		}
	}
	return result
}

func search(r []int, left, right, sub int) int {
	if left > right {
		return -1
	}
	mid := left + (right-left)/2
	if r[mid] == sub {
		return mid
	}else if r[mid] < sub {
		return search(r, mid+1, right, sub)
	}else {
		return search(r, left, mid-1, sub)
	}
}
```
