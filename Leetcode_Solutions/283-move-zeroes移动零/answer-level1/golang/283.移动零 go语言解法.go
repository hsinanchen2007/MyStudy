### 解题思路

用双指针法，把非零元素移动到前面，再把后面的位置全部填0就行了

### 代码

```golang
func moveZeroes(nums []int)  {
	var p int = 0
	for i := 0;i < len(nums);i++ {
		if nums[i] != 0 {
			nums[p] = nums[i]
			p++
		}
	}
	for i := p;i < len(nums);i++ {
		nums[i] = 0
	}
}
```