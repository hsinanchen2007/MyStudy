```go
//faster
func largestNumber(nums []int) string {
	strNums := make([]string, len(nums))
	for i, num := range nums {
		strNums[i] = strconv.Itoa(num)
	}
	sort.Slice(strNums, func(i, j int) bool {
		return strNums[i] + strNums[j] > strNums[j] + strNums[i];
	})
	if strNums[0] == "0" {
		return "0"
	}

	return strings.Join(strNums, "")
}

//simple
func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		s1 := strconv.Itoa(nums[i])
		s2 := strconv.Itoa(nums[j])
		return s1 + s2 > s2 + s1;
	})
	if nums[0] == 0 {
		return "0"
	}
	return strings.Replace(strings.Trim(fmt.Sprint(nums), "[]"), " ", "", -1)
}
```
