1、递归解法
本来想先用递归实现，然后再考虑优化版本，谁知道提交后显示在空间和时间方面能满足要求，难道是因为没有人用golang提交过？


```golang
func BuildEveryResult(leftNums, curRes []int, result *[][]int) {
	if len(leftNums) == 1 {
		curRes = append(curRes, leftNums[0])
		*result = append(*result, curRes)
		return
	}

	for i := 0; i < len(leftNums); i++ {
		newLeft := make([]int, 0)
		for j := 0; j < len(leftNums); j++ {
			if i != j {
				newLeft = append(newLeft, leftNums[j])
			}
		}

		newRes := make([]int, len(curRes) + 1)
		for j := 0; j < len(curRes); j++ {
			newRes[j] = curRes[j]
		}
		newRes[len(curRes)] = leftNums[i]

		BuildEveryResult(newLeft, newRes, result)
	}
}

func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	curRes := make([]int, 0)
	result := make([][]int, 0)
	BuildEveryResult(nums, curRes, &result)

	return result
}
```

![image.png](https://pic.leetcode-cn.com/892eef8b67f9d51676295d11ad3919239a23ee928701d1b751503691f15a10f7-image.png)
