### 解题思路
本题的O(n)的解法的思路是：使用maxfit记录最大利润，使用minprice记录最小值(股票的最低点)。
接下来就是遍历数组，不断求最大值和最小值，当有当前利润大时替换掉原来的最大利润；当前价格小时，替换掉原来的最小价格。
**当前利润=当前价格-最小价格。**
也就是，找当前价格卖出时，什么时候买入能收到最大价值，这个当然是最小值时买入了。

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices)<=0{
        return 0
    }
    minPrice:=int(^uint(0)>>1)                  //go语言中的最大int值
    maxfit:=0

    for i,_:=range prices{
        maxfit=max(prices[i]-minPrice,maxfit)   //求当前值卖出时所得最大利润
        minPrice=min(prices[i],minPrice)        //找到最小值
    }

    return maxfit
}

func min(a,b int) int{
    if a>b{
        return b
    }
    return a
}

func max(a,b int) int{
    if a>b{
        return a
    }

    return b
}
```