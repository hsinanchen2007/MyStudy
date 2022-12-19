### 解题思路
思路很多
1. 排序之后从头开始找，找到连续个 x 的数量超过 n/2 停止返回 x，时间复杂度是 O(nlogn) + O(k)
2. 空间换时间，用 HashMap 存储数值和他的数量，出现一个 HashMap 对应的 key 的 value++，当某个 key 数量超过 n/2 之后，返回 key，时间复杂度 O(k)，最差 O(n)

下面代码是思路二的简单实现

### 代码

```golang
func majorityElement(nums []int) int {
	m := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		m[nums[i]]++
		if m[nums[i]] > len(nums)/2 {
			return nums[i]
		}
	}
	return 0
}
```