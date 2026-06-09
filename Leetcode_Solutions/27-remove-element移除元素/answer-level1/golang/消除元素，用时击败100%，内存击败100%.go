### 解题思路
这题相比消除数组中重复项更简单，主要思路如下
1. 注意go slice删除元素后长度会变
2. 删除元素后，记得循环中的 【增量下标索引】 要减一

### 代码

```golang
func removeElement(nums []int, val int) int {
    for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			nums = append(nums[:i], nums[i+1:]...)
			i--
		}
	}
	return len(nums)
}
```