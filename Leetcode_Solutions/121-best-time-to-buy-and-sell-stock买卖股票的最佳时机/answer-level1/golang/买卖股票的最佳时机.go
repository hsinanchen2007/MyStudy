## 结果

![image.png](https://pic.leetcode-cn.com/47cc3adac5376e2a1295c27dd14b62bdb31bf491f3bfabc4f2f76cda95bc3d00-image.png)

## 思路

遍历一次，保存遍历过的最小点，在往后遍历的过程中更新max值即可

```
func maxProfit(prices []int) int {
    n := len(prices)
    if n == 0 {
        return 0
    }
    var max int
    var min = prices[0]
    for i:=1;i<n;i++ {
        if prices[i] < min {
            min = prices[i]
        } else if prices[i] - min > max {
            max = prices[i] - min
        }
    }
    return max
}
```

