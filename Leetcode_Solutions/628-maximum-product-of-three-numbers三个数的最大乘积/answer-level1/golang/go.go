### 解题思路
此处撰写解题思路
只有两种可能，要么最后面三个数相乘，要么最后面一个数加前面两个负数相乘
### 代码

```golang
func maximumProduct(nums []int) int {
	sort.Ints(nums)
	
	if nums[0]*nums[1]>nums[len(nums)-2]*nums[len(nums)-3]{
		return nums[0]*nums[1]*nums[len(nums)-1]
	}
	return nums[len(nums)-1]*nums[len(nums)-2]*nums[len(nums)-3]
}
```