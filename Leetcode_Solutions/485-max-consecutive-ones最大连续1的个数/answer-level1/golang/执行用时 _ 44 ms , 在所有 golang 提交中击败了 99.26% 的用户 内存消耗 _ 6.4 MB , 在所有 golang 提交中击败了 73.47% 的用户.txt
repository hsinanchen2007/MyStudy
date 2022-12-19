思路：
j指针找1，每找到一个1，自加。
当j碰到非1时候，结算i与maxLen来决定是否更新最长长度。

```
func findMaxConsecutiveOnes(nums []int) int {
	numLen := len(nums)
	jLimit := numLen - 1
	var maxLen int

	for i, j := 0, 0; j < numLen; j++ {
		for nums[j] == 1 {
			i++
			if j < jLimit {
				j++
			} else {
				// j走到最后一个元素，直接结算
				break
			}
		}
		if i > maxLen {
			maxLen = i
		}
		// 当前长度清零
		i = 0
	}
	return maxLen
}
```

![image.png](https://pic.leetcode-cn.com/166906d9d5692fab4b7066998ba0045f631a8354a1a212465d9f3cf419648be4-image.png)
