### 1、粗暴
```
func mySqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
```

### 2、二分查找，查找第一个小于等于给定值的元素
```
func mySqrt(x int) int {
	start := 0
	end := x/2 + 1

	for start <= end {
		mid := start + (end-start)/2
		if mid*mid > x { //到左区间进行查找
			end = mid - 1
		} else {                     //到右区间查找
			if (mid+1)*(mid+1) > x { //如果 mid+1 的平方大于 x ，return mid
				return mid
			}
			start = mid + 1
		}
	}
	return -1
}
```
