题解：
```
func heightChecker(heights []int) int {
    count := 0
    hc := make([]int, 101)
    for _, v := range heights {
		hc[v]++
	}
    j := 0
    for i := 1;i < len(hc); i++ {
		for hc[i] > 0 {
			if heights[j] != i {
				count++
			}
			j++
			hc[i]--
		}
	}
    return count
}
```
思路：
非递减序列 的意思是序列里任意相邻的两个数，后面的那个数不比前面的那个数小；
递增序列序列其实应该有“不严格递增”与“严格递增”两种；
不严格递增的意思等价于非递减序列; 
而严格递增序列的意思是序列里任意相邻的两个数，后面的那个数大于前面的那个数；
但这两种序列都是非递减的

首先需要申请一个大小为 101 的Golang slice hc。因为数组总长为100，对应的数
据处理是从1开始的，到现在已经有了 101 个变量，编号从 a[0]~a[100]。一开始将
 a[0]~a[100]都初始化为 0，表示这些hc里都还没有数据，接着开始遍历heights，
将对应的值做为hc的下标放进hc里面，也就是将要排序的数据进行了非递减排序，最后
对比hc和heights对应位置的值，不同则count加1，count的值即为所求。
