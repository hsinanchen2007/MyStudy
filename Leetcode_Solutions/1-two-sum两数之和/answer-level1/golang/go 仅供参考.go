
```
func twoSum(numbers []int, target int) []int {
	/* 使用 make 函数 */
	numMap := make(map[int]int)
	length := len(numbers)
	value := []int{}
	var key int
	for index := 0; index < length; index++ {
		numMap[numbers[index]] = index
	}
	for k, v := range numbers {
		key = target - v
		if numMap[key]>0 && numMap[key] != k {
			value = append(value, k)
			value = append(value, numMap[key])
			break
		}
	}
    return value
}

```
