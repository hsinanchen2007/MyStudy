根据题目数据特征，可以使用桶排序思路，使用三次循环完成，时间复杂度为 O(n)，空间复杂度为 O(m+n)，m 为可能出现的数字种类数

第一次循环：遍历原数组，统计每个数字出现次数
第二次循环：遍历统计数组，求出小于每个数字的数字数
第三次循环：根据统计结果，修改原数组，将结果写入

```go
// 执行耗时:4 ms,击败了100.00% 的Go用户
// 内存消耗:3 MB,击败了100.00% 的Go用户
func smallerNumbersThanCurrent(nums []int) []int {
	statistic := make([][101]int, 2)
	for _, num := range nums { // 统计数量
		statistic[0][num]++
	}
	for i := 1; i < 101; i++ {
		statistic[1][i] = statistic[1][i-1] + statistic[0][i-1]
	}
	for i, num := range nums {
		nums[i] = statistic[1][num]
	}
	return nums
}
```
