# Hash
```
func findDisappearedNumbers(nums []int) []int {
	var hash = map[int]int{}
	var result = []int{}
	for _,value := range nums {
		hash[value] = 1
	}
	for i := 1;i <= len(nums);i++{
		if hash[i] == 0{
			result = append(result, i)
		}
	}
	return result
}
```
# 原地
```
func findDisappearedNumbers(nums []int) []int {
	for i := 0;i<len(nums) ;i++  {
		var newIndex int
		if nums[i] < 0{
			newIndex = -nums[i]-1
		}else{
			newIndex = nums[i]-1
		}

		if nums[newIndex] >0{
			nums[newIndex] = -nums[newIndex]
		}
	}
	fmt.Println(nums)
	var result = make([]int,0)
	for i := 0;i<len(nums) ;i++  {
		if nums[i] > 0{
			result = append(result, i+1)
		}
	}
	return result
}
```
