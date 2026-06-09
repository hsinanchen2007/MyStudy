根据题意可以得到，在第i个位置，此时可以选择在i+1,i+2...i+nums[i]中选择一个作为下一个跳跃的位置。因此假如后面这些位置的最短跳跃次数都已经得知，我们可以直接在这n个位置中选择出跳跃次数最小的作为下一个节点。
也就有 f(i) = 1 + min(f(i+1), f(i+2) ... f(i+MaxOffset))，其中MaxOffset为1到nums[i]中最大的使新下标合法的值
且有边界条件：f(n-1)=0，最终求f(0)

复杂度分析：算法是O(n^2)，但是配合一些合理的剪枝条件，效率还是可以的（至少在测试数据集做到了100%）

结果：
![image.png](https://pic.leetcode-cn.com/509729b1f8cf3a9819e67232511bb228f56e6ce66c18ec948f357902b5738ab3-image.png)

```Go []
// 2019/10/17 23:56 by fzls
func jump(nums []int) int {
	n := len(nums)
	if n <= 1 {
		return 0
	}

	dp := make([]int, n)
	dp[n-1] = 0

	for i := n - 2; i >= 0; i-- {
		if i+nums[i] >= n-1 {
			dp[i] = 1
			continue
		}

		maxIdx := i + nums[i]
		if maxIdx >= n {
			maxIdx = n - 1
		}
		ms := math.MaxInt32
		for j := maxIdx; j > i; j-- {
			if dp[j] < ms {
				ms = dp[j]
				if ms == 1 {
					break
				}
			}
		}
		dp[i] = 1 + ms
	}

	return dp[0]
}

```

