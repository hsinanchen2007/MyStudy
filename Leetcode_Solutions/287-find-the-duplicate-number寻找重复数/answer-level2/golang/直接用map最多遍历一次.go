```
func findDuplicate(nums []int) int {
    num := make(map[int]int)
    var i int
    for i=0; i<len(nums);i++ {
		num[nums[i]]++;
		if num[nums[i]]>1 {break}
	}
    return nums[i] 
}
```
