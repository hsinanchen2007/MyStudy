### 解题思路
此处撰写解题思路

### 代码

```golang
func topKFrequent(nums []int, k int) []int {
	// 统计频率 key为数字 value为次数
	cnt := make(map[int]int)
	for _, value := range nums {
		cnt[value] ++
	}
	// 创建桶 及初始化
	buckets := make([][]int, len(nums)+1)
	for i := 0; i < len(buckets); i++ {
		buckets[i] = make([]int, 0)
	}
	// 建立以频率为index的桶  就是将相同频率的key放入同一个桶
	for k, v := range cnt {
		buckets[v] = append(buckets[v], k)
	}
	// 统计前k个
	var res []int
	for l, count := len(buckets)-1, k; l >= 0 && count > 0; l-- {
		if len(buckets[l]) == 0{
			continue
		} else {
			num := len(buckets[l])
			res = append(res, buckets[l]...)
			count = count - num
		}
	}
	return res
}
```