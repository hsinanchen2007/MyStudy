### 解题思路
数学方法

### 代码
```golang
func distributeCandies(candies int, num_people int) []int {
	var (
		result = make([]int, num_people)
		p      = int(math.Floor(math.Sqrt((float64(2*candies) + 0.25)) - 0.5))
		remain = candies - ((1 + p) * p / 2)
		level  = (p / num_people) + 1
		pos    = (p % num_people)
	)
	for i := 0; i < num_people; i++ {
		if i < pos {
			result[i] = level * (p - pos + 2*i + 2) / 2
		}
		if i == pos {
			result[i] = (level-1)*(i+1) + (level-1)*(level-2)*num_people/2 + remain
		}
		if i > pos {
			result[i] = (level-1)*(i+1) + (level-1)*(level-2)*num_people/2
		}
	}
	return result
}
```