
#### 思路
方法大致与快速排序相同
1. 随机选择一个数作为中值, 然后遍历数组将小于中值的数字交换到左侧,大于中值的到右侧.
2. 根据右侧数量判断
    1. 如果右侧大于中值的数量等于 k-1, 那中值就是第k大的, 返回中值
    2. 右侧数量大于等于k, 递归在右侧继续查找
    3. 上面两个条件都不满足, 则递归继续在左侧查找

#### 代码
```
func findKthLargest(nums []int, k int) int {

	l := len(nums)
	mark := 1

	//随机选择中值
	r := rand.Intn(l)
	selected := nums[r]
	nums[r], nums[0] = nums[0], nums[r]

	for i := 1; i < l; i++ {
		if nums[i] < selected {
			nums[mark], nums[i] = nums[i], nums[mark]
			mark++
		}
	}

	rightCount := l - mark

	//右侧大于中值的数量等于 k-1, 那中值就是第k大的
	if rightCount == k - 1 {
		return selected
	}

	//右侧数量大于等于k, 在右侧继续查找
	if rightCount >= k {
		return findKthLargest(nums[mark:l], k)
	}

	//在左侧继续查找
	return findKthLargest(nums[1:mark], k - rightCount - 1)
}
```

<br />

![image.png](https://pic.leetcode-cn.com/c0334af55551d670bc99eb540702cef5e7f255ffe278b08dad46c2238429ea73-image.png)
