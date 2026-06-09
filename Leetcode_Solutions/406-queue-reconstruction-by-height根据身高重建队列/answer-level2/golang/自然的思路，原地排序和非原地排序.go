```text
题意有点不好理解，这样想一下：
本来所有人站成一队（不一定有序），这时候统计下每个人前边有几个身高大于等于自己的人
突然，打乱了这些人的顺序~~~
问题是恢复这些人的顺序
```
想起学生时代排队跑操~
```text
很自然的思路：
先按照k升序排序（或者按照身高降序排序），再微调， 原地排序
时间复杂度O(n^2),空间复杂度O(1)
```
```go
func reconstructQueue(people [][]int) [][]int {
	// 先根据k从小到大排序
	sort.Slice(people, func(i, j int) bool {
		return people[i][1] < people[j][1]
	})
	// 由h、k微调顺序
	for i := 1; i < len(people); i++ { // 如果一开始是按照身高降序排序的，这里微调需要从后往前调整
		p := people[i]
		k := p[1]
		countK := 0 // 统计前边比p高的人数
		j := 0
		// 如果countK 大于 k，需要把这个娃往前移动，j记录需要移动到的位置
		// 如果countK 等于 k，则无需移动;因一开始排序的原因，不会出现countK 小于 k的情况
		for ; j < i; j++ {
			if people[j][0] >= p[0] {
				countK++
				if countK > k {
					break
				}
			}
		}
		if countK > k {
			tmp := []int{p[0], p[1]}
			_ = copy(people[j+1:i+1], people[j:i])
			people[j] = tmp
		}
	}
	return people
}
```
```text
如果新开辟一个数组，不用在原地排序，且一开始的预排序多做一点点，代码会简单些
预处理时不但要按身高降序排列，身高相同的时候还要按照k升序排列
然后从头开始将人们一一放入新开辟的数组，放的时候处理逻辑变得简单
时间复杂度O(n^2)，空间复杂度O(n)
看起来和第一个方法时间复杂度一样，但其实一开始排序多做了一点点，导致后边微调时减少了不少移动，实际要比第一个方法快一点点
```
```go
func reconstructQueue1(people [][]int) [][]int {
	// 高的排前边，一样高的按照k升序排列
	sort.Slice(people, func(i, j int) bool {
		if people[i][0] == people[j][0] {
			return people[i][1] < people[j][1]
		}
		return people[i][0] > people[j][0]
	})
	result := make([][]int, 0)
	for i := 0; i < len(people); i++ {
		p := people[i]
		k := p[1]
		if k >= len(result) {
			result = append(result, p)
		} else {
			// 在result的索引k处插入
			result = append(result, []int{})
			_ = copy(result[k+1:], result[k:])
			result[k] = p
		}
	}
	return result
}
```