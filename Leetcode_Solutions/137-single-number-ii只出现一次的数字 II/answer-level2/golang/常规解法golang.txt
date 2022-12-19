全数据累加和单个出现累加。 （3*单个出现累加-全数据累加 ） / 2  获得结果

```
func singleNumber(nums []int) int {

	singleMap := make(map[int]bool)

	sum := 0
	for i := range nums {
		sum += nums[i]
		singleMap[nums[i]] = true
	}

	singleSum := 0
	for k, _ := range singleMap {
		singleSum += k
	}

	return (3*singleSum - sum) / 2
}
```
