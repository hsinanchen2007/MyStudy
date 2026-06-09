### 解题思路
二分查找法

### 代码

```golang
func missingNumber(nums []int) int {
	// 1.数组数量为0
	if len(nums) == 0 {
		return 0
	}
	left := 0
	right := len(nums) 
	// 
	for left < right {
		middle := (left + right) >> 1
		if nums[middle] != middle {
			right = middle    // 左面就已经不一致了 , 向左移动
		}else{
			left = middle +1
		}
	}
	return left
}

```