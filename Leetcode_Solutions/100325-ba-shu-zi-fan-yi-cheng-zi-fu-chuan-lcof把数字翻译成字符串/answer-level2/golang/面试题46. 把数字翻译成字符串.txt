### 解题思路
瞎写
1. dfs
2. 动态规划


### 代码

```golang
func translateNum(num int) int {
	numStr := fmt.Sprintf("%d", num)
	res := helper(numStr, 0)
	return res
}

func helper(str string, idx int) int {
	if len(str) == idx {
		return 1
	}
	r := []rune(str)
	if idx == len(str)-1 || str[idx] == '0' || string(r[idx:idx+2]) > "25" {
		return helper(str, idx+1)
	}
	return helper(str, idx+1) + helper(str, idx+2)
}
```