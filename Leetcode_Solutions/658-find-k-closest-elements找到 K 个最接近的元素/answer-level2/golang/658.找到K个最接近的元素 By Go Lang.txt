### 解题思路
此题思路二分查找，以此索引为起点定义两个left,right指针，根据比较left元素，和right元素与目标值的绝对值差，决定left,right指针的移动。
也就是left--或者right++。注意边界即可。


### 代码

```golang

func findClosestElements(arr []int, k int, x int) []int {
	s, e := 0, len(arr)-1
	m := -1
	for {
		m = s + (e-s)/2
		if arr[m] == x {
			break
		} else if arr[m] < x {
			s = m + 1
		} else {
			e = m
		}
		if s == e {
			m = s
			break
		}
	}

	ABS := func(n int) int {
		if n < 0 {
			return -n
		}
		return n
	}
	div := ABS(arr[m] - x)
	base := m
	if m > 0 && ABS(arr[m-1]-x) <= div {
		div = ABS(arr[m-1] - x)
		base = m - 1
	}
	if m < len(arr)-1 && ABS(arr[m+1]-x) < div {
		div = ABS(arr[m+1] - x)
		base = m + 1
	}

	left, right := base, base
	for right-left < k-1 {
		leftDiv, rightDiv := 20001, 20001
		if left > 0 {
			leftDiv = ABS(arr[left-1] - x)
		}
		if right < len(arr)-1 {
			rightDiv = ABS(arr[right+1] - x)
		}
		if leftDiv > rightDiv {
			right++
		} else {
			left--
		}
	}
	return arr[left : right+1]
}
```