### 解题思路

### 代码

```golang
func removeDuplicates(nums []int) int {
	location :=0
	if len(nums)!= 0 {
		for i:=0;i<len(nums) ;i++  {
			if nums[i] > nums[location] {
				nums[location+1] = nums[i]
				location++
			}
		}
	}
	return location+1
}
```