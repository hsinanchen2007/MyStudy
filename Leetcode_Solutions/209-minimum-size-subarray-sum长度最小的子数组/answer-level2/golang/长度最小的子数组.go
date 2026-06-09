### 解题思路
滑动窗口（双指针）
	解题思路：
		1. 定义两个指针i, j, i为滑窗左框，j为滑窗右框
		2. 两者通过分别向右滑动，前者能使窗口之间的和减小，后者能使窗口之间的和增大。开始时二者重合，窗口的和就是重合点所在的数
		3. j向右滑动，使sum增大
		4. 当sum大于等于s时，记录滑窗所包括的子数组长度ans, 若ans已有数值，则判断新旧值，取小者。此时i向右滑动，缩小窗口内sum，若依然sum >= s，
		则i继续右滑至sum < s或 i = j
		5. 重复3，4步骤。直至j到达数组最后侧

### 代码

```golang
func minSubArrayLen(s int, nums []int) int {
    i, j, sum, ans, l := 0, 0, 0, int(^uint(0)>>1), len(nums)

	for ; j < l; j++ {
		sum += nums[j]
		for sum >= s {
			// 窗口长度
			wSize := j - i + 1
			if ans > wSize {
				ans = wSize
			}

			// 减去左框值
			sum -= nums[i]
			// 左框向右滑动
			i++
		}
	}

	if ans != int(^uint(0)>>1) {
		return ans
	} else {
		return 0
	}
}
```


> 时间复杂度O(n)

> 空间复杂度O(1)