### 解题思路
打卡
### 代码

```golang
func maxProfit(prices []int) int {
    n:=len(prices)
    if n<=1{
        return 0
    }
    res:=-1
    max,min:=prices[0],prices[0]
    for i:=1;i<n;i++{
        if prices[i]<min{
            min=prices[i]
            max=prices[i]
        }else if prices[i]>max{
            max=prices[i]
        }
        if res<max-min{
            res=max-min
        }
    }
    return res
}
```