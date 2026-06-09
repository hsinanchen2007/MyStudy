### 解题思路
其实转化之后 就是数一数 里面有多少个奇数 多少个偶数 然后取 这两个数量里面的最小值即可

### 代码

```golang
func minInt2(a, b int) int {
	if a <= b {
		return a
	}
	return b
} 


func minCostToMoveChips(chips []int) int {
	oddCnt := 0
	evenCnt := 0
	for _, c := range chips {
		if c & 1 != 0 {
			oddCnt++
		} else {
			evenCnt++
		}
	}
	return minInt2(evenCnt, oddCnt)
}
```