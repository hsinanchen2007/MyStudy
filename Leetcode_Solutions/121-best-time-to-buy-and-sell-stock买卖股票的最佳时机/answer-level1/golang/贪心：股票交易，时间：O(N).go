### 解题思路
题意：股票只能交易一次，找出交易最大值
思路：找出交易日的最小值，同时判断当前交易是否能获取到更大值，注意边界值。时间：O(N)

### 代码

```golang
func maxProfit(prices []int) int {
	if len(prices) == 0 {
		return 0
	}
    ans := 0
	min := prices[0]
	for i := 1; i < len(prices); i++ {
		if prices[i]-min > ans {
			ans = prices[i] - min
		}
		if min > prices[i] {
			min = prices[i]
		}
	}

	return ans
}
```