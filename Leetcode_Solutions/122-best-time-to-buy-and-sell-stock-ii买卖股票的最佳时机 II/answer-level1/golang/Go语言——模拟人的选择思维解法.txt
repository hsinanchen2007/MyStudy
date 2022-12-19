### 解题思路
本题解法完全模拟人的选择思维。选择一个低的点作为买入点，之后算受益，用一个变量记录下受益的最大值maxfit。如果此值卖出获得的受益更大，则改变maxfit。如果此值买入获得的受益降低，说明上一个获得maxfit的时刻该卖出，则加到sumProfit中，同时调整买入时刻和最大值。

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices)<=0{
        return 0
    }

    sumProfit:=0
    buyPrice:=int(^uint(0)>>1)
    maxfit:=0
    for _,p:=range prices{
        if p-buyPrice>maxfit{
            maxfit=p-buyPrice
        }else{
            sumProfit+=maxfit
            buyPrice=p
            maxfit=0
        }
    }
    sumProfit+=maxfit
    return sumProfit
}
```