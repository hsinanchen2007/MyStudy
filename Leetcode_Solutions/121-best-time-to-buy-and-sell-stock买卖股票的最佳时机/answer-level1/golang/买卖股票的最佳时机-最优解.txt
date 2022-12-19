### 解题思路
假设从第一天购买
如果后一天比前一天股价高，就计算利润，如果比之前利润高就更换最大利润。
如果后一天比前一天股价低，就更换股票购买日。

#### 关于覆盖率
因为股价是一直向后走的，不会向前减。所以碰见最低股价，就要持有，只有最低的股价才可能跟后面的股价有更大的差值。
虽然前面股价不是低高价，但也许会有最高利润。最低价买入，后面不一定还有更大的涨幅。所以要一直计算最大利润。

### 代码

```golang
func maxProfit(prices []int) int {
    // 最大利润
    result := 0
    if len(prices) <= 1 {
        return result
    }
    // 最低股价
    min := prices[0]
    for _, v := range prices[1:] {
       if v < min {
           min = v
       } else if v > min {
           if v-min > result {
               result = v-min
           }
       }
    }
    return result
}
```