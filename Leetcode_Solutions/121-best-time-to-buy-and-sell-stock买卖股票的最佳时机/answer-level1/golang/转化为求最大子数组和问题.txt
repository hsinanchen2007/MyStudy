### 解题思路
此处撰写解题思路

### 代码

```golang
//将股票价格数组转化为股票涨跌数组，则问题转化为求最大子数组和问题
//动态规划解法，时间复杂度O(n),空间复杂度O(n)

func maxProfit(prices []int) int {
    
    l := len(prices)
    if l == 0 {
        return 0
    }
    max := 0
    nums := make([]int, l)

    nums[0] = 0
    for i:=1; i<l;i++ {
        nums[i] = prices[i] - prices[i-1]
    }

    for i:=1; i<l; i++ {
        if nums[i-1] > 0 {
            nums[i] += nums[i-1]
        }
        if nums[i] > max {
            max = nums[i]
        }
    }
    return max
}
```