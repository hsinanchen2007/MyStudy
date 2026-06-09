# 第一思路-暴力解法

```go
func distributeCandies(candies int, num_people int) []int {
	kid := make([]int, num_people)
	n := 0           // 每次分糖果的个数
	count := candies // 糖果的总数
	i := 0           // 分糖果的次数
	for {
		count -= n   // 每次分多少
		if count <= i {
			kid[i%num_people] += count
			break
		}
		n++
		kid[i%num_people] += n
		i++
	}
	return kid
}
```
