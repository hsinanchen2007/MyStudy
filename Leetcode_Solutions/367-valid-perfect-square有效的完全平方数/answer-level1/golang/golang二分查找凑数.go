### 解题思路
思路很简单、就是感觉leetcode上golang代码太少、哈哈
需要注意的就是边界问题和中位数问题

### 代码

```golang
func isPerfectSquare(num int) bool {
    l := 0
	r := num
	for l <= r {
		mid := (l + r) / 2
		if mid * mid == num {
			return true
		}
		if mid * mid > num {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return false
}
```