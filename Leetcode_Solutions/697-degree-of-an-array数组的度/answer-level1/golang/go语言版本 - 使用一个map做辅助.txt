### 解题思路
本解法来自公众号**算法和数据结构的峡谷**

这道题的这种解法主要是使用了一个辅助的map，map的k是nums的值，map的值是一个slice（可以理解为数组）这个slice中存放了
关于这个nums中值的下标举个例子： 1 1 1 2 3 4 那么map[1] = []int{0,1,2}

当把所有的值放入到map中并且记录了下标后，我们开始遍历这个map只要找到slice中len最大，并且slice中第一个跟最后一个
的差最小的就是我们要求的数量

### 代码

```golang
func findShortestSubArray(nums []int) int {
	// 边界判断，如果是0就返回0就OK
    if len(nums) == 0 { 
        return 0
    }
	 // 创建一个辅助哈希，哈希v是一个切片
	r := make(map[int][]int)
	for k,v := range nums {
		if _,ok := r[v];ok {
			r[v] = append(r[v],k)
		}else {
			// 因为不知道len，所以这个slice最开始创建要使用len == 1
			a := make([]int,1,1)
			a[0] = k
			r[v] = a
		}
	}

	// 1 是数量 2 是index的距离 result 就是最后的一个输出指针，
	// 所有的值跟result不断的比较，然后最终result就是真实要输出的值。
	// 因为只需要两个值，并且不存在数组的复制，所以直接使用数组就OK了，
	// 没必要使用slice。
	result := [2]int{0,0} 

	for _,v := range r {

		// 先比len，len大的取胜，如果len一样，那么下标差小的取胜。
		if result[0] < len(v) || result[0] == len(v) && result[1] > v[len(v)-1] - v[0]{
			result = [2]int{len(v),v[len(v)-1] - v[0]}
		}

	}

	return result[1]+1
}
```

> 最后吐槽一下力扣的 markdown转码系统真的不好用。转码以后的显示真的不如GitHub，改进一下。