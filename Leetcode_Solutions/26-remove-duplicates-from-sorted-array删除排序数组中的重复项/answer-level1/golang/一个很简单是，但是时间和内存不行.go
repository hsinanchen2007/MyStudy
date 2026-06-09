### 解题思路
遍历对比，和下一个元素相同就删除

### 代码

```golang
func removeDuplicates(nums []int) int {
    var i int
	for i<len(nums)-1{
		if nums[i] == nums[i+1] {
			nums = append(nums[:i], nums[i+1:]...)
		}else{
			i++
		}
	}
	return len(nums)
}
```