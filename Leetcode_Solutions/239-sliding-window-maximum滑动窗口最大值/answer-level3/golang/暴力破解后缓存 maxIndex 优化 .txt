![FireShot Capture 047 - 239. 滑动窗口最大值 - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/6dc1df2ff71f310dcde89329ee133dfe1e6a85604681fc9f334a266ab79eb8b2-FireShot%20Capture%20047%20-%20239.%20%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)

缓存了上一个 maxIndex，能尽量少便利就少便利

```
func maxSlidingWindow(nums []int, k int) []int {
    if nums == nil{
		return []int{}
	}

	numLen := len(nums)
	var maxValue int
	var nowValue int
	var maxIndex int = math.MinInt64 //将上一个最大值的下标缓存起来
	var res []int = make([]int, 0, numLen-k+1)

	for i := k-1; i < numLen; i++ {
        //使用缓存的 index 进行一步判断
		if maxIndex <= i && maxIndex >= i-k+1 {
			if nums[maxIndex] <= nums[i] {
				res = append(res, nums[i])
				maxIndex = i
			} else {
				res = append(res, nums[maxIndex])
			}
			continue
		}
        //缓存 index 用不了时再遍历数据
        maxValue = math.MinInt64
		for j := k-1; j >= 0; j-- {
			nowValue = nums[i-j]
			if nowValue >= maxValue {
				maxIndex = i-j
				maxValue = nowValue
			}
		}
		res = append(res, maxValue)
	}

	return res
}
```
