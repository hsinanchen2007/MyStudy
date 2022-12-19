### 解题思路
这里是用递归法解决组合总和的问题，方法有待改进，可以考虑动态规划的方法

### 代码

```golang
func GetCombine(candidates, thisRes []int, lastChoise, left int, outResult *[][]int)  {
	if left == 0 {
		*outResult = append(*outResult, thisRes)
		return
	}

	for _, value := range candidates {
		if value < lastChoise { // 选取的数递增，用于去重
			continue
		}
		if left < value { // 当前数小于剩余数时，不用再检查
			continue
		}

		newRes := make([]int, len(thisRes)+1)
		copy(newRes, thisRes[:len(thisRes):len(thisRes)])
		newRes[len(thisRes)] = value

		GetCombine(candidates, newRes, value, left - value, outResult)
	}
}

func combinationSum(candidates []int, target int) [][]int {
	outResult := make([][]int, 0)
	GetCombine(candidates, nil, 0, target, &outResult)
	return outResult
}
```