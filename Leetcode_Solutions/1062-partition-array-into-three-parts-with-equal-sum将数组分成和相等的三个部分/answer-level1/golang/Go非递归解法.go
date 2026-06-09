首先对数组求和，数组和非3的倍数时直接判断结果为false。
然后数组进行循环并求和，当求和值等于总和的三分之一时清零，继续循环并求和，当再次等于总和的三分之一时，剩余部分的和必然和前两次求和结果相同，此时可直接返回判断结果为true。

```
执行用时 : 76 ms, 在Partition Array Into Three Parts With Equal Sum的Go提交中击败了93.18% 的用户
内存消耗 : 7 MB, 在Partition Array Into Three Parts With Equal Sum的Go提交中击败了94.74% 的用户
```

```go []
func canThreePartsEqualSum(A []int) bool {
	sum := 0
	for _, n := range A {
		sum += n
	}
	if sum%3 != 0 {
		return false
	}
	sum1, sum2 := sum/3, sum/3
	for i := range A {
		if sum1 != 0 {
			sum1 -= A[i]
		} else if sum2 != 0 {
			sum2 -= A[i]
			if sum2 == 0 {
				return true
			}
		}
	}
	return false
}
