### 解题思路
根据题目，只要找到第一个小于前一个的数就可以了；找不到就输出数组第一个数。

### 代码

```golang
func minArray(numbers []int) int {
		for i := 0; i < len(numbers)-1; i++ {
		if numbers[i] > numbers[i+1]{
			return numbers[i+1]
		}
	}
	return numbers[0]
}
```

### 免责说明
这肯定不是最优的解法。
可能是测试用例比较小，还拿了双百的结果（哭笑）。
博君一乐。