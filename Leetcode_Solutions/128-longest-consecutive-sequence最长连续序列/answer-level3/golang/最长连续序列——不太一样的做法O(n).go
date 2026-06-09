# 解法：哈希表+(伪)动态规划

其实我自己都不太清楚算什么方法了，就是想到了这么写，如果有对算法理论比较懂的大佬路过，还望指点一下。下面是代码：

```go
func longestConsecutive4(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	// 一方面，visited用于记录数是否出现过(由于前面set已去重，所以这里并未其效果)
	// 另一方面，visited的值为当前这个数所在的连续序列的新长度
	visited := make(map[int]int)

	// 伪动态规划？
	left, right := 0, 0		// 就是两个临时变量
	for i:=0; i<n; i++ {

		if visited[nums[i]] > 0 {continue}	// 访问过了
		visited[nums[i]] = 1
		// 下面这里两个代码段处理了三种情况：
		// 2 3 4 5(cur) 6 7 8
		// 这里要清楚的是只要是visited[k-1]或者visited[k+1] >0
		// 就意味着他们是连续的，中间插不了数了
		// 我们可以在每一次更新的时候更新序列两端记录的序列长度值（只有序列两端的数，其映射的值才是序列长度值）

		left, right = visited[nums[i]-1], visited[nums[i]+1]	// 这是因为k-visited[k-1]有可能=k-1，从而导致其原本值被修改
		if left > 0 && right > 0 {
			visited[nums[i]-left] += right + 1       // 序列起点
			visited[nums[i]+right] = visited[nums[i]-left] // 序列终点处记录的序列长度更新
			continue
		}
		if left > 0 && right==0 {
			visited[nums[i]] += left 	// k成为新终点
			visited[nums[i]-left] = visited[nums[i]]
			continue
		}
		if left==0 && right > 0 {
			visited[nums[i]] += right           // k成为新起点
			visited[nums[i]+right] = visited[nums[i]] // 序列终点处记录的序列长度更新
			continue
		}
	}

	// 遍历visited，得最大值
	maxcount := 0
	for _, v := range visited {
		if v > maxcount {
			maxcount = v
		}
	}

	return maxcount
}
```


