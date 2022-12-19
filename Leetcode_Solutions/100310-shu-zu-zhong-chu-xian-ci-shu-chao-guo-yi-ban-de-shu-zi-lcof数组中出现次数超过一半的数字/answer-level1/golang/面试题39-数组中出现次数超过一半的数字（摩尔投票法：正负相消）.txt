### 解题思路
日常学习[@jyd](/u/jyd/)大佬
[大佬详细地址传送门](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/)

### 知识点：摩尔投票法：正负相消

### 代码

```golang
func majorityElement(nums []int) int {
    x, votes := nums[0], 1 // x 为假设的众数，votes为票数
	for i := 1; i < len(nums); i++ {
		if votes == 0 { // 票数归零，重新设当前元素为众数，准备开始新一轮的计票
			x = nums[i] 
		}

		if nums[i] == x { // 若当前数字等于众数x，则票数+1，否则-1
			votes++
		} else {
			votes--
		}
	}

	return x
}
```