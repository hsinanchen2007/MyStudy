### 解题思路
此处撰写解题思路

### 代码

```golang
func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	count:=0
	for i:=0;i< len(nums);i++{
		count+=nums[i]
		i++
	}
	return count
}
```