先找到最小的，然后如果最小的位置大于k，那么先去这个位置左边的k个数，如果小于k，则直接取arr的前k个数作为结果，然后在从当前这个位置后面开始遍历，发现有比之前结果第一个数小的则移除第一个数，再把该数加到数组后面，直到遇到大于等于第一个数位置，r就是最终结果
```
func findClosestElements(arr []int, k int, x int) []int {
 	min, minIdx := 10000, 0
	for idx, v := range arr {
		c := math.Abs(float64(v - x))
		if int(c) < min {
			min = int(c)
			minIdx = idx
		}
	}

	r := []int{}
	tail := 0
	if minIdx+1 >= k {
		r = arr[minIdx+1-k : minIdx+1]
		tail = minIdx + 1
	} else {
		r = arr[:k]
		tail = k
	}

	for i := tail; i < len(arr); i++ {
		c := int(math.Abs(float64(arr[i] - x)))
		c0 := int(math.Abs(float64(r[0] - x)))
		if c >= c0 {
			break
		}
		r = r[1:]
		r = append(r, arr[i])
	}
	return r
}
```
*******************
补充一种双指针
```
func findClosestElements(arr []int, k int, x int) []int {
	if x <= arr[0] {
		return arr[:k]
	}
	if x >= arr[len(arr)-1] {
		return arr[len(arr)-k:len(arr)]
	}
	left,right := 0,len(arr)-1
	for right - left + 1 > k {
		if x - arr[left] > arr[right] - x {
			left++
		}else {
			right--
		}
	}
	return arr[left:right+1]
}
```

