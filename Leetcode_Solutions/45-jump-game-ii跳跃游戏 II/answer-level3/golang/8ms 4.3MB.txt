### 解题思路
此处撰写解题思路

贪婪算法 ，
- 每次跳跃最长
- 如果当前的范围可以替换[preLen,maxLen],那么当前的节点就可以替换上一个节点

### 代码

```golang
func jump(nums []int) int {
	for i := range nums {
		nums[i] = i + nums[i]
	}

	return minSteps(nums)
}

func minSteps(nums []int) int {
	inLen := len(nums)
	if inLen == 0 || inLen == 1 {
		return 0
	}

	var maxLen, preLen int
	steps := 1
	for i := range nums {
		if maxLen < i { //中间断掉了
			return -1
		}

		//提前返回
		if maxLen >= inLen-1 {
			return steps
		}

		// 当前已经能够覆盖到maxLen,但是 i能覆盖的却小于 maxLen，肯定不考虑当前i
		if nums[i] <= maxLen {
			continue
		}

		//如果i<=preLen 那么就表明i可以替换i-1，并且可以负责更广的区域
		if i > preLen {
			preLen = maxLen
			steps++
		}
		maxLen = nums[i]

	}
	return steps
}

```