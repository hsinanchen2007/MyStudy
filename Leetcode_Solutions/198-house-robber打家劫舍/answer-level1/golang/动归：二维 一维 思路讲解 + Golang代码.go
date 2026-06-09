**二维 dp 思路**

首先，这道题乍一看是能用递归暴力求解的，其次，可以通过记录中间的结果进行递推。
因此这道题可以用动归求解
由于每间房子都可以选择偷与不偷，因此在写状态方程的时候就会遇到这个困难：如何判断或区分出前一个房子偷了没呢？
一个比较简单的想法就是，用二维数组，一个维度表示房间索引，一个维度表示偷与没偷即可。
状态方程：
    dp[i][0] = Max(dp[i-1][0], dp[i-1][1])
    dp[i][1] = nums[i] + dp[i-1][0]
dp数组中的值表示从第0个房子开始一直到第i个房子，所能偷到的最大金额。二维下标1与0分别表示第i间房子偷了还是没有偷。
针对第i间房子，分情况讨论：如果要偷，那么其值应该为上一家没有偷的最大金额加上这间房子的金额；如果不偷则是上一间房间针对偷与没偷两种
可能性的金额选大的那一个。
最终结果应该不难想到，是最后一天中两种可能的最大值：Max(dp[n-1][0], dp[n-1][1])

代码：
```
func rob(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}

	dp := make2dSlice(len(nums), 2)
	dp[0][0], dp[0][1] = 0, nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i][1] = dp[i-1][0] + nums[i]
		dp[i][0] = max2Int(dp[i-1][1], dp[i-1][0])
	}

	return max2Int(dp[len(dp)-1][1], dp[len(dp)-1][0])
}

func max2Int(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func make2dSlice(i, j int) [][]int {
	sl := make([][]int, i)
	for k := range sl {
		sl[k] = make([]int, j)
	}

	return sl
}
```

**将二维 dp 数组优化为一维 dp 数组**

dp[i] = Max(dp[i-1], dp[i-2] + nums[i])
思路：
	不用一个维度表示偷与没有偷，而是直接用dp[i]表示从第1个房子直到第i个房子，无论第i个房子
	偷了没有。
	dp[i] = Max(dp[i-1], dp[i-2] + nums[i])
	这样会不会有问题呢？毕竟我们不知道数组中的元素表示的到底是当天偷了还是没偷。
	所以直觉上我们会觉得会出现一些错误：
		1. 第i-1天偷了，但是第i天又偷了。
		2. 第i-1天没偷，然而第i天也没偷。
	首先看第1中，这种从表达式中就能排除，因为根本没有dp[i-1]+nums[i]这种组合。
	着重分析下第2种情况，如果发生了这种情况，从表达式看， Max(dp[i-1], dp[i-2] + nums[i])
	中，即dp[i-1]本身表示的是i-1没有偷，但是我们还是选择了dp[i-1],反推一下即：
	dp[i-1] > dp[i-2] + nums[i]
	那么这种情况存在吗？存在的话就说明不能这么做。
	答案是不存在。当dp[i-1]没偷的时候： dp[i-1] == dp[i-2] ; 且 nums[i] > 0
	因此必然：dp[i-1] < dp[i-2] + nums[i]
	通过反证法，可以证得，一维的优化思路没有问题。

代码：

```
func rob(nums []int) int {
	if nums == nil {
		return 0
	}
	n := len(nums)
	if n == 0 {
		return 0
	}
	dp := make([]int, n+1)
	dp[0], dp[1] = 0, nums[0]
	for i := 2; i <= n; i++ {
		dp[i] = max2Int(dp[i-1], dp[i-2]+nums[i-1])
	}
	return dp[n]
}
```

这里有个技巧，就是让dp数组多一个元素且初始化dp[0] = 0
这么做的好处主要是可以让dp[2]即第2个房子符合动归方程，否则一开始判断与初始化比较啰嗦

以下是“啰嗦版”的代码，供大家参考。比较值得注意的是对dp[1]的初始化赋值

```
func rob(nums []int) int {
	if nums == nil {
		return 0
	}
	n := len(nums)
	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}
	if n == 2 {
		return max2Int(nums[0], nums[1])
	}

	dp := make([]int, n)
	dp[0] = nums[0]

	if nums[0] < nums[1] {
		dp[1] = nums[1]
	} else {
		dp[1] = nums[0]
	}

	for i := 2; i < n; i++ {
		dp[i] = max2Int(dp[i-1], dp[i-2]+nums[i])
	}

	return dp[n-1]
```
