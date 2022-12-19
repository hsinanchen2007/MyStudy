思路：快慢双指针

```
func removeElement(nums []int, val int) int {
	numLen := len(nums)
	indexLimit := numLen - 1
	// 慢指针i，快指针j
	var i, j int
	for ; j < numLen; i++ {
		for nums[j] == val {
			// 防止快指针在内部循环越界
			if j < indexLimit {
				j++
			} else {
				return i
			}
		}
		nums[i] = nums[j]
		j++
	}
	return i
}
```
![image.png](https://pic.leetcode-cn.com/f35234ca5dc9f3478b104b442628461251baa9c4c53e75546bd56609f0d203c7-image.png)
