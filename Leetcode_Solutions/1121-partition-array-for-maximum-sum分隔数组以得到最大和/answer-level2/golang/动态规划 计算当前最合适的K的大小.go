1. 计算当前节点（i）可以分割到的最后节点 i + k - 1
1. 遍历当前节点到最后节点，作为 当前子数组的最后节点
1. 当前节点为j，则开始节点为start = j - k + 1 到 i 之间
1. 子数组长度为 (j  - t + 1)
1. 动态计算 sum[j] 的最大值
```
func maxSumAfterPartitioning(A []int, K int) int {
	sum := make([]int, len(A))
	for i := 0; i < len(A); i++ {
		end := i + K - 1
		if end >= len(A) {
			end = len(A) - 1
		}
		for j := i; j <= end; j++ {
			start := j - K + 1
			if start < 0 {
				start = 0
			}
			for t := start; t <= i; t++ {
				pre := 0
				if t - 1 >= 0 {
					pre = sum[t-1]
				}
				sum[j] = Max(sum[j], pre + A[i] * (j - t + 1))
			}
		}
	}
	return sum[len(A)-1]
}

func Max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}
```