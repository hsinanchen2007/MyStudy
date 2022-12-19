```
func rotate(nums []int, k int) {
	numMoveFront:=k%len(nums)
	// 整体反转数组
	reverseNums(nums)
	// 反转前numMoveFront个元素，即将需要移到前面的元素移动完毕
	reverseNums(nums[:numMoveFront])
	// 反转后面的元素，即将不需要移到开头的元素全部后移
	reverseNums(nums[numMoveFront:])
}

// 反转数组
func reverseNums(nums []int) {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}
```

![image.png](https://pic.leetcode-cn.com/2d5231d716a95f6391687075e3f1be68ffa413c43163a414c2094badee7d30dd-image.png)


