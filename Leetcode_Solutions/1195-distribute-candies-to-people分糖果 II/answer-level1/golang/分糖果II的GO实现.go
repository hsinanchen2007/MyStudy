时间复杂度O（N）
空间复杂度O（1）
```
func distributeCandies(candies int, num_people int) []int {
	i := 1
	result := make([]int, num_people)
	position := 0
	count := 0
    for {
		count += i
		if count >= candies {
			result[position] += candies - count  + i
			break
		}
		result[position] += i

		position ++
        i++
		if position > num_people - 1 {
			position = 0
		}
	}
	return result
}
```
