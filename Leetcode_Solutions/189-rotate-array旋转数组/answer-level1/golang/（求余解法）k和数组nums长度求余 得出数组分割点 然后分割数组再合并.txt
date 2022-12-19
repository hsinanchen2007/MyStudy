### 解题思路
此处撰写解题思路

### 代码

```golang
func rotate(nums []int, k int)   {
	len := len(nums)
	index := len - k % len
	newNums := append(nums[index:],nums[:index]...)
	for i :=0 ;i < len ;i++  {
		nums[i] = newNums[i]
	}
}
```