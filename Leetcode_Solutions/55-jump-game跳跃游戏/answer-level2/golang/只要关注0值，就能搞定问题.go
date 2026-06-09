从题目意思很容易知道，只要这个数组中没有0值，那怎么样都能跳到终点，比如[3, 2, 1, 1]；所以我们只要关注0值就好了。
从后往前推，当碰到0值时，我们继续往前的时候就关注当前位置能否跳过这个0值，比如[3, 2, 1, 0, 1]，由于0往前的3, 2, 1都跳不过0，所以结果为false。只要途中碰到的0值我们都能跳过，就一定能到达终点，比如[1, 2, 3, 0, 1]，由于“3”步可以跳过0，所以返回true。

```
func canJump(nums []int) bool {
	l := len(nums)
	if l < 1 {
		return false
	}

	// 自己跳自己
	if l == 1 {
		return true
	}

	// 一开始就跳不动了
	if nums[0] == 0 {
		return false
	}

	zero := -1
	for i := l - 2; i >= 0; i-- {
		// 已经有0值了
		if zero > 0 {
			// 可以跳过0值
			if i+nums[i] > zero {
				// 当前0值可以忽略
				zero = -1
			}

			continue
		}

		if nums[i] == 0 {
			zero = i
			continue
		}

	}

	if zero < 0 {
		return true
	}

	return false
}
```

