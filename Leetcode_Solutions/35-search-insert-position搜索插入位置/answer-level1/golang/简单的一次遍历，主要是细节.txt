### 解题思路
没啥好说的

### 代码

```golang
func searchInsert(nums []int, target int) int {
	for i:=0;i<len(nums);i++{
		if nums[i]>=target{
			return i
			break
		}
	}
	return len(nums)
}

```