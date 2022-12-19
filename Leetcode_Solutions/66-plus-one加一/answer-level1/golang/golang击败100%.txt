未修改原数组
```
执行用时 :0 ms, 在所有 golang 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 golang 提交中击败了99.56%的用户
```

### 代码

```golang
func plusOne(digits []int) []int {
	res := make([]int, len(digits)+1)
	length := len(digits)
	jinwei := 0
	for i := length - 1; i >= 0; i-- {
		if i == length-1 {
			jinwei = (digits[i] + 1) / 10
			res[i+1] = (digits[i] + 1) % 10
			continue
		}
		res[i+1] = (digits[i] + jinwei) % 10
		jinwei = (digits[i] + jinwei) / 10
	}
	if jinwei > 0 {
		res[0] = jinwei
	} else {
		// 去掉开头的0
		res = res[1:]
	}
	return res
}
```