```
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
  for i:=0;i<len(nums)-1;i++{
  	for j:=i+1;j<len(nums);j++{
  		if int(math.Abs(float64(nums[i]-nums[j])))<=t && int(math.Abs(float64(i - j)))<=k{
  			return true
		}

	}
  }
  return false
}
```
