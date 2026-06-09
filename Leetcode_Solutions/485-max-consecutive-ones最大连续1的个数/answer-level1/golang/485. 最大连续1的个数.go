"与"运算:
0&0=0
0&1=0
1&0=0
1&1=1


对数组的元素累积进行"与"运算; "与"运算结果是 0, 表示不是连续的 1, 如果"与"运算结果是 1, 表示是连续的 1;
记录下最大的连续是 1 的长度,就是所求

```
func findMaxConsecutiveOnes(nums []int) int {
	n := -1
	nMax := 0
	length := 0
	for _, v := range nums {
		if n == -1 {
			n = 1
		}

		n &= v
		if n != 0 {
			length++
			if length > nMax {
				nMax = length
			}
		} else {
			length = 0
			n = -1
		}
	}

	return nMax
}
```