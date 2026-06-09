## Golang 解法
![image.png](https://pic.leetcode-cn.com/39e39e02ba00a7dd12c0ab227427d55a26505f5d01edf57c1485e66a2edb1f1b-image.png)

### 分析
- 局部倒置首先是一个全局倒置，因此无需统计局部倒置.
- 一旦发现是全局倒置，且不是局部倒置的排列，直接返回false.
- 是全局倒置，且不是局部倒置的情况：后方(j)比前方(i)小，且不是相邻元素.
- 仅需统计0到i项的max值，检测i+2的值是否小于max值即可。
- Leetcode的Markdown没法写数学公式，凑合着画一下：
```
check 为比较的点，o 为空出来的位置，max为x列的最大值。

|--- max ---| > | check |
| x | x | x | o | check |
```
- 一旦check小于max，就直接返回false了。

### 编码
```go
func isIdealPermutation(A []int) bool {
	if len(A) < 3 {
		return true
	}

	max := A[0]
	for i := 2; i < len(A); i++ {
		if A[i] < max {
			return false
		}

		if A[i - 1] > max {
			max = A[i - 1]
		}
	}

	return true
}
```

