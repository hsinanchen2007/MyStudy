思路受到 “两数之和” 那道题的启发： 计算两个数之间的关系，正常的暴力破解的思维是需要循环套循环 O(n*n)的时间复杂度。
但是可以利用两数之间的关系， 把其中一个转换为另一个，这样只需要一层for循环即可。
本题中的两数关系为：  x-y=k 那么有  x=y+k 和 y=x-k。
只要把数组中的所有数据都存储到哈希表中，遍历时，检查 x+k 和 x-k 是否在数组中即可。
此外用另一个哈希表来记录diff对。只需记录diff对中的较大值或较小值即可。我记录的是较小值。
代码如下：
```
func findPairs(nums []int, k int) int {
	if k < 0 {
		return 0
	}
	numsHas := make(map[int]bool)
	diffHas := make(map[int]bool)

	for _, num := range nums {
		if numsHas[num - k] {
			diffHas[num - k] = true
		}
		if numsHas[num + k] {
			diffHas[num] = true
		}
		numsHas[num] = true
	}
	return len(diffHas)
}
```

