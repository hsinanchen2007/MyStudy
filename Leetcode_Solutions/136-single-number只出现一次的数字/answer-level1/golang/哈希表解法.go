### 解题思路
1. 利用哈希表存储数组中每个数字出现的次数，其中键为数组元素，值为出现次数。
2. 利用哈希表查找和删除的时间复杂度均为 O(1) 的特性，在每次插入前，先判断要插入的数组元素是否存在，存在则删除，这样能保证循环完数组后在哈希表中只有一个键值对，也就是我们需要找到的那个数组元素。

### 代码

```golang
func singleNumber(nums []int) int {
	var num2cnt = make(map[int]int)

	for _, num := range nums {
		if _, ok := num2cnt[num]; ok {
			delete(num2cnt, num)
		} else {
			num2cnt[num] = 1
		}
	}

	for num := range num2cnt {
		return num
	}

	return 0
}
```