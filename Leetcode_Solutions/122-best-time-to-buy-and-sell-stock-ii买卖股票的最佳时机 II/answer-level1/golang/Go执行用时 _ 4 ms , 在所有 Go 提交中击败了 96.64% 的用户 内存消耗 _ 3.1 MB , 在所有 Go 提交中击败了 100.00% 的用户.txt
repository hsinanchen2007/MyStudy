### 解题思路
此处撰写解题思路
low 和high 记录每次买入卖出的最低值和最高值
遍历，寻找每一次峰值之前的最小值买入，
即low为一次峰值中的最小值，high为峰顶
利润 res+=high-low
返回res即可

### 代码

```golang
func maxProfit(prices []int) int {
	l := len(prices)
	if l <= 1 {
		return 0
	}
	high := 0
	low := prices[0]
	res := 0
	for i := 0; i < l; i++ {
		if prices[i] > high && prices[i] > low {
			high = prices[i]
		} else if low < high {
			res = res + high - low
			high = 0
			low = prices[i]
		}
		if low > prices[i] {
			low = prices[i]
		}
		if i == l-1 && low < high {
			res = res + high - low
		}
	}
	return res
}
```