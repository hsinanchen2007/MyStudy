### 解题思路
重要的说三遍：

**chips中的元素是位置！chips中的元素是位置！chips中的元素是位置！**

1、所有偶数位置的数移动到同一偶数位置，花费0
2、所有奇数位置的数移动到同一奇数位置，花费0
3、将数少的移动到数多的位置。

总结：统计奇数和偶数的个数，返回较小数

### 代码

```golang
func minCostToMoveChips(chips []int) int {
	cnt_odd, cnt_even := 0, 0
	for _, num := range chips{
		if num % 2 == 0{
			cnt_even++
		} else {
			cnt_odd++
		}
	}
	return min(cnt_even, cnt_odd)
}
func min(a, b int) int {
	if a > b {
		return b
	}
	 return a
}
```