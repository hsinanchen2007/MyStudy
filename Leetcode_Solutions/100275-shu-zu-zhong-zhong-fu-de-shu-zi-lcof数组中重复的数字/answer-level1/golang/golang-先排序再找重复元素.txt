解题思路：
比较简单就是先排序，然后循环排序结果。算法复杂度：O(n*log(n))。

golang代码：
`
func findRepeatNumber(nums []int) int {
	sort.Ints(nums)    //这里可以自己实现排序算法，也可以直接用sort包中的排序算法。golang sort包中的排序算法比较有意思：排序元素小等12个元素时使用的是希尔排序，大于12个元素时使用的是快速排序，有兴趣的可以看看源码。
	lastNUm := nums[0] //初始化重复返回值为排序后首个元素
	for _, num := range nums[1:] { 
		if lastNUm == num { //遍历数组，当前元素若与上一个元素相同则为目标重复元素
			break
		} else {
			lastNUm = num
		}
	}
	return lastNUm
}
`

运行结果：
执行用时：48 ms, 在所有 Go 提交中击败了49.79%的用户
内存消耗：6.8 MB, 在所有 Go 提交中击败了100.00%的用户

csdn链接：
https://blog.csdn.net/u014615155/article/details/105406374