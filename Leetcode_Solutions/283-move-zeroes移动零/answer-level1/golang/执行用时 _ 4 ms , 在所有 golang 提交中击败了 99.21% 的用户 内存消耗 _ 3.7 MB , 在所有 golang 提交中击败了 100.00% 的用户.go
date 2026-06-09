思路：双指针。快指针在后面找非0元素，找到后利用慢指针更新前面数组。当快指针遍历完数组后，慢指针后面的元素全填0.

```
func moveZeroes(nums []int) {
	numsLen := len(nums)
	var slowIndex int
	// 双指针，一快一慢
	for fastIndex := 0; ; slowIndex++ {
		// 快指针在找后面非0的元素
		for fastIndex < numsLen && nums[fastIndex] == 0 {
			fastIndex++
		}

		if fastIndex < numsLen {
			// 找到就更新慢指针
			nums[slowIndex] = nums[fastIndex]
			fastIndex++
		}else{
				// 快指针已经遍历完数组，退出
				break
		}

	}
	// 当快指针全部遍历完数组后，将慢指针后面的元素全赋成0
	for ; slowIndex < numsLen; slowIndex++ {
		nums[slowIndex] = 0
	}
}

```
![image.png](https://pic.leetcode-cn.com/6158c3c22cf91b73c0ad1ff975fee90cf0d486bbafc19f1e9fea998ce2ba6080-image.png)
