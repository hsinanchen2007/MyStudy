### 解题思路

1.暴力法

```golang
func arrangeCoins(n int) int {
	var res int
	for i := 1;i <= n;i++ {
		sum := (1 + i) * i / 2
		if sum == n {
			res = i
			break
		}
		if sum > n {
			res = i - 1
			break
		}
	}
	return res
}
```


2.二分法

```golang
func arrangeCoins(n int) int {
	var left,right int = 0,n
	var mid int
	for left < right {
		mid = (left + right + 1) / 2
		sum := (1 + mid) * mid / 2
		if sum > n {
			right = mid - 1
		}else {
			left = mid
		}
	}
	return left
}
```
