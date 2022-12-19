### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0fe09322ac3afbffa8703072cbbe2edfc6ecd076c252b7c28a0bda11641e27a3-image.png)

### 代码


```golang
func maxSlidingWindow(nums []int, k int) []int {
	var result []int
	if len(nums) == 0 {
		return result
	}
	if k == 1 {
		return nums
	}
	// 构造第一个滑窗的递减队列
	// 例如 [4,3,2,22,3,4,5], 5, 此时第一个滑窗[4,3,2,22,3]的递减队列为[22, 3]
	// 后续都会对这个递减队列进行修改
	var max_queue []int
	max, max_index, n := nums[0], 0, len(nums)
	max_queue = append(max_queue, max)
	for i := 1; i < len(nums[:k]); i++ {
		if max < nums[i] { // 如果当前为最大值，则需要清空整个递减队列，将最大值放到队首
			max = nums[i]
			max_queue = max_queue[0:0]
			max_queue = append(max_queue, max)
			max_index = i
		} else {
			if i > max_index {
				pos := len(max_queue)
				for j := pos - 1; j >= 0; j-- {
					if nums[i] > max_queue[j] {
						pos--
					} else {
						break
					}
				}
				max_queue = max_queue[0:pos]
				max_queue = append(max_queue, nums[i])
			}
		}
	}
	// 记录第一个滑窗的结果
	result = append(result, max_queue[0])
	// 更新滑窗递减队列的同时更新滑窗结果
	for i := 1; i+k <= n; i++ {
		if max_queue[0] == nums[i-1] {
			max_queue = max_queue[1:]
		}
		pos := len(max_queue)
		for j := pos - 1; j >= 0; j-- {
			if nums[i+k-1] > max_queue[j] {
				pos--
			} else {
				break
			}
		}
		max_queue = max_queue[0:pos]
		max_queue = append(max_queue, nums[i+k-1])
		result = append(result, max_queue[0])
	}
	return result
}

```