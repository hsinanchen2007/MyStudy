### 解题思路
此处撰写解题思路

### 代码

```golang
func massage(nums []int) int {
	var ans = make([]int,0)
	if len(nums) == 0{
		return 0
	}else if len(nums) == 1{
		return nums[0]
	}else if len(nums)==2{
		return int(math.Max(float64(nums[0]), float64(nums[1])))
	}else{
		ans = append(ans, nums[0])
		ans = append(ans,int(math.Max(float64(nums[0]), float64(nums[1]))))
		for i:=2;i<len(nums);i++{
			var temp = ans[i-2] + nums[i]
			ans = append(ans,int(math.Max(float64(ans[i-1]), float64(temp))))
		}
	}
	return ans[len(nums)-1]
}
```