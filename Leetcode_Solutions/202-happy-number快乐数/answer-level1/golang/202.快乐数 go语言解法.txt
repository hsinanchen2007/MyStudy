### 解题思路

如果是不快乐数，那么一定会进入一个死循环内。所以可以用一个map来存放出现过的平方和，如果之后再次出现，就说明为不快乐数，如果出现1，则为快乐数

### 代码

```golang
func isHappy(n int) bool {
	m := make(map[int]bool)
	var sum int = sum2(n)
	m[sum] = true
	for {
		if sum == 1 {
			return true
		}
		sum = sum2(sum)
		if _,ok := m[sum];ok {
			return false
		}else {
            m[sum] = true
        }
	}
}
func sum2(n int) int {
	var sum int
	var s int
	for {
		if n == 0{
			return sum
		}
		s = n % 10
		sum += s * s
		n /= 10
	}
}
```