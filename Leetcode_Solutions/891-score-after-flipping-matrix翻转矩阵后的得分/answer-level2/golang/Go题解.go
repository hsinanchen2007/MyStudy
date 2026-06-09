以数组[][]int{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}}为例：
1. 通过列变换，将A[0]元素中的所有值变成1，得到{{1, 1, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}}
2. 从A[1]开始遍历数组，对0开头的行进行行变换，得到{{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}}
3. 从A[0]的最后一位（A[0][3]）开始遍历数组求和，求和的方法为：统计该列值1的个数，若1的个数大于0的个数直接求和，反之列反转求和。

```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.3 MB, 在所有 Go 提交中击败了20.00%的用户
```

```Go []
func matrixScore(A [][]int) int {
	for i := range A[0] {
		if A[0][i] == 0 {
			for j := range A {
				if A[j][i] == 0 {
					A[j][i] = 1
				} else {
					A[j][i] = 0
				}
			}
		}
	}
	for i := range A {
		if A[i][0] == 0 {
			for j := range A[i] {
				if A[i][j] == 0 {
					A[i][j] = 1
				} else {
					A[i][j] = 0
				}
			}
		}
	}
	sum, cnt := 0, 0
	base := 1
	for i := len(A[0]) - 1; i >= 0; i-- {
		for j := range A {
			if A[j][i] == 1 {
				cnt++
			}
		}
		if cnt >= len(A)-cnt {
			sum += cnt * base
		} else {
			sum += (len(A) - cnt) * base
		}
		base *= 2
		cnt = 0
	}
	return sum
}
```

更多LeetCode题库Go语言题解参考
[LeetCodeByGo](https://github.com/mrandmrsbenben/LeetCodeByGo)