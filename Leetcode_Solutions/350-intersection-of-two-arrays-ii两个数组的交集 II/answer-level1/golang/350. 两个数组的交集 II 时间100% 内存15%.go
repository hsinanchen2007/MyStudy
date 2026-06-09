### 解题思路
算法：map统计出现次数。再遍历任一map，num打印较小次数。
时间：O(n)
空间：O(n)，map可用数组优化

### 代码

```golang
func min(m, n int) int {
	if m < n {
		return m
	}
	return n
}
func intersect(nums1 []int, nums2 []int) []int {
	// map1分配内存了，长度可以动态扩容，默认value为0
	map1 := make(map[int]int)
	for _, num := range nums1 {
		map1[num]++
	}

	map2 := make(map[int]int)
	for _, num := range nums2 {
		map2[num]++
	}

	// 已分配内存，为可变长度的数组
	var res []int
	for k,v := range map1 {
		v2 := map2[k]
		for i := 0; i < min(v, v2); i++ {
			res = append(res, k)
		}
	}

	return res
}
```