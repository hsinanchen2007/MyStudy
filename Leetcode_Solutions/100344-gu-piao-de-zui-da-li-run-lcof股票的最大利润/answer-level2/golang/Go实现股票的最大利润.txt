

```golang
func maxProfit(prices []int) int {
    if prices == nil|| len(prices)==0{
        return 0
    }
    min := prices[0]
    res := 0
    for i := 0;i<len(prices);i++{
        min = Min(min,prices[i])
        res = Max(res,prices[i]-min)
    }
    return res
}

func Max(a,b int)int{
    if a>b{
        return a
    }else{
        return b
    }
}

func Min(a,b int)int{
    if a>b{
        return b
    }else{
        return a
    }
}
```