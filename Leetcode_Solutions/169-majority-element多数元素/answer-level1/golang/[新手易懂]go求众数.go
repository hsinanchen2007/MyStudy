1 暴力 for for O(n2)
2 map O(n)
3 排序后取 sortHash[n/2] O(nlogn)
4 分治 分开两半算，得出出现最多的left,right,如果一致就是它，不一致再算下count(left), count(right)  O(nlogn)
5 摩尔投票法 O(N)

第二种解法   （因为题目说了一定有答案才可以这样）
```
func majorityElement(nums []int) int {
	l := len(nums)
	threshold := l / 2
	counter := make(map[int]int)

	for i := 0; i < l; i++ {
		num := nums[i]
		counter[num]++
		if counter[num] > threshold {
			return num
		}
	}
	return -1
}
```

第三种解法
```
func majorityElement(nums []int) int {
    sort.Ints(nums)
    return nums[len(nums)/2]
}
```

第五种解法 
```
func majorityElement(nums []int) int {
   current, count := 0, 0
	for _, v := range nums {
		if count == 0 {
			current = v
			count++ // 计算当前的数字出现的次数
		} else if current == v {
			count++
		} else {
			count--
		}
	}
	return current
}
```
